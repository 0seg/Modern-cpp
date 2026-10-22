#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
    int age;
};

void print_students(const char* label, const std::vector<Student>& students) {
    std::cout << label << '\n';

    for (const auto& student : students) {
        std::cout << student.name << " | Score: " << student.score << " | Age: " << student.age << '\n';
    }
}

int main() {
    std::vector<Student> students{
        {"Luis", 88, 21},
        {"Ana", 95, 20},
        {"Mia", 78, 22},
        {"Pedro", 91, 19},
        {"Carlos", 95, 23}
    };

    print_students("Original students:", students);

    // 1. Sort by score in ascending order.
    std::ranges::sort(students, std::ranges::less{}, &Student::score);

    print_students("\nSorted by score (ascending):", students);

    // 2. Sort by score in descending order.
    std::ranges::sort(students, std::ranges::greater{}, &Student::score);

    print_students("\nSorted by score (descending):", students);

    // 3. Find a student by name.
    auto found = std::ranges::find(students, std::string{"Pedro"}, &Student::name);

    if (found != students.end()) {
        std::cout << "\nFound student: " << found->name << ", score: " << found->score << '\n';
    }

    // 4. Find the student with the highest score.
    auto best = std::ranges::max_element(students, std::ranges::less{}, &Student::score);

    if (best != students.end()) {
        std::cout << "Highest score: " << best->name << " - " << best->score << '\n';
    }

    // 5. Find the youngest student.
    auto youngest = std::ranges::min_element(students, std::ranges::less{}, &Student::age);

    if (youngest != students.end()) {
        std::cout << "Youngest student: " << youngest->name << ", age: " << youngest->age << '\n';
    }

    return 0;
}