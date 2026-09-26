/*
 * Unique Pointer Array in C++
 */

#include <iostream>
#include <memory>
#include <string>

class Person {
public:
    Person(std::string name, int age)
        : name{name}, age{age} {}

    void display() {
        std::cout << "Name: " << name
                  << ", Age: " << age << '\n';
    }

    ~Person() {
        std::cout << "Destructor called for "
                  << name << '\n';
    }

private:
    std::string name;
    int age;
};

int main() {

    std::unique_ptr<Person[]> people{
        new Person[3]{
            Person{"Alice", 30},
            Person{"Bob", 25},
            Person{"Charlie", 35}
        }
    };

    for (int i = 0; i < 3; ++i) {
        people[i].display();
    }

    return 0;
}