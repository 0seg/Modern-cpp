#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, int id)
        : name_{name}, id_{id} {}

    void displayInfo() const {
        std::cout << "Name: " << name_
                  << ", ID: " << id_ << '\n';
    }

protected:
    std::string name_;
    int id_;
};

class Developer : public Employee {
public:
    Developer(const std::string& name, int id,
              const std::string& language)
        : Employee{name, id},
          language_{language} {}

    void code() const {
        std::cout << name_ << " is coding in "
                  << language_ << '\n';
    }

private:
    std::string language_;
};

int main() {
    Developer dev{"sofia", 101, "C++"};

    dev.displayInfo(); 
    dev.code();        
}