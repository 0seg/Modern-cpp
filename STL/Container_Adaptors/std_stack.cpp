/* std::stack in C++ */


#include <iostream>
#include <stack>
#include <string>

int main() {
    // A stack follows LIFO: Last In, First Out.
    // Example: actions that can be undone in reverse order.
    std::stack<std::string> actions;

    actions.push("Open file");
    actions.push("Edit text");
    actions.push("Change font");
    actions.emplace("Save file");

    std::cout << "Actions stored: " << actions.size() << '\n';
    std::cout << "Next action on top: " << actions.top() << '\n';

    // Remove the most recently added action.
    actions.pop();
    std::cout << "After pop, top: " << actions.top() << '\n';

    std::cout << "\nUndoing actions:\n";
    while (!actions.empty()) {
        std::cout << "Undo: " << actions.top() << '\n';
        actions.pop();
    }

    std::cout << "Stack empty? " << std::boolalpha << actions.empty() << '\n';
    return 0;
}

