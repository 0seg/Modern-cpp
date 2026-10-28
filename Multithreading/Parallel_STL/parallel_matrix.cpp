
#include <vector>
#include <iostream>
#include <thread>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <chrono>

class Matrix {
    int* data;
    int rows;
    int cols;

public:
    Matrix(int _n, int _m) : data(nullptr), rows(_n), cols(_m) {
        if (rows <= 0 || cols <= 0)
            throw std::invalid_argument("Invalid matrix dimensions");

        data = new int[static_cast<std::size_t>(rows) * cols]{};
    }

    ~Matrix() {
        delete[] data;
    }

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    void set_value(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw std::out_of_range("Invalid matrix index");

        data[i * cols + j] = value;
    }

    int get_value(int i, int j) {
        return data[i * cols + j];
    }

    void set_all_values(int value) {
        std::fill(data, data + rows * cols, value);
    }

    static void sequential_multiply(Matrix* A, Matrix* B, Matrix* C) {
        if (A->cols != B->rows ||
            C->rows != A->rows ||
            C->cols != B->cols)
            throw std::invalid_argument("Incompatible matrix dimensions");

        for (int i = 0; i < C->rows; ++i) {
            for (int j = 0; j < C->cols; ++j) {
                int sum = 0;

                for (int k = 0; k < A->cols; ++k) {
                    sum += A->data[i * A->cols + k]
                         * B->data[k * B->cols + j];
                }

                C->data[i * C->cols + j] = sum;
            }
        }
    }

    static void parallel_multiply(Matrix* A, Matrix* B, Matrix* C) {
        if (!A || !B || !C)
            throw std::invalid_argument("Null matrix pointer");

        if (A->cols != B->rows ||
            C->rows != A->rows ||
            C->cols != B->cols)
            throw std::invalid_argument("Incompatible matrix dimensions");

        struct process_data_chunk {
            void operator()(
                Matrix* A, Matrix* B, Matrix* C,
                std::size_t start, std::size_t end)
            {
                for (std::size_t index = start; index < end; ++index) {
                    const std::size_t row = index / C->cols;
                    const std::size_t col = index % C->cols;

                    int sum = 0;

                    for (int k = 0; k < A->cols; ++k) {
                        sum += A->data[row * A->cols + k]
                             * B->data[k * B->cols + col];
                    }

                    C->data[index] = sum;
                }
            }
        };

        struct join_threads {
            std::vector<std::thread>& threads;

            ~join_threads() {
                for (auto& thread : threads) {
                    if (thread.joinable())
                        thread.join();
                }
            }
        };

        const std::size_t length =
            static_cast<std::size_t>(C->rows) * C->cols;

        const std::size_t min_per_thread = 10000;

        const std::size_t max_threads =
            (length + min_per_thread - 1) / min_per_thread;

        const unsigned int hardware_threads =
            std::thread::hardware_concurrency();

        const std::size_t num_threads = std::min(
            static_cast<std::size_t>(
                hardware_threads != 0 ? hardware_threads : 2),
            max_threads
        );

        const std::size_t block_size = length / num_threads;

        std::vector<std::thread> threads(num_threads - 1);

        std::size_t block_end = 0;

        {
            join_threads joiner{threads};

            for (std::size_t i = 0; i < num_threads - 1; ++i) {
                const std::size_t block_start = i * block_size;
                block_end = block_start + block_size;

                threads[i] = std::thread(
                    process_data_chunk{},
                    A, B, C,
                    block_start, block_end
                );
            }

            process_data_chunk{}(
                A, B, C, block_end, length
            );
        }
    }
};

int main() {
    const int SIZE = 3000;

    Matrix A(SIZE, SIZE);
    Matrix B(SIZE, SIZE);
    Matrix C1(SIZE, SIZE);
    Matrix C2(SIZE, SIZE);

    A.set_all_values(1);
    B.set_all_values(2);

    auto start = std::chrono::steady_clock::now();

    Matrix::sequential_multiply(&A, &B, &C1);

    auto end = std::chrono::steady_clock::now();

    double sequential_time =
        std::chrono::duration<double, std::milli>(
            end - start).count();

    start = std::chrono::steady_clock::now();

    Matrix::parallel_multiply(&A, &B, &C2);

    end = std::chrono::steady_clock::now();

    double parallel_time =
        std::chrono::duration<double, std::milli>(
            end - start).count();

    std::cout << "Sequential: " << sequential_time << " ms\n";
    std::cout << "Parallel:   " << parallel_time << " ms\n";

    if (parallel_time > 0) {
        std::cout << "Speedup: "
                  << sequential_time / parallel_time << "x\n";
    }

    std::cout << "Results: "
              << (C1.get_value(0, 0) == C2.get_value(0, 0)
                  ? "Match" : "Do not match")
              << '\n';

    return 0;
}
