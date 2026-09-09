/* Using std::optional in C++ - Output Functions */

#include <iostream>
#include <optional>

std::optional<size_t> find_character(const std::string& str, char c){
    //If found set return index, else return std::nullopt

    for(size_t i{}; i<str.size(); ++i){
        if(str[i] == c) return i;
    }
    return std::nullopt;

}

int main(){
    std:: string str{"Hello, World!"};

    char c{'W'};

    std::optional<int> result = find_character(str, c); //Calling the function to find the character

    if(result.has_value()){
        std::cout << "Character '" << c << "' found at index: " << result.value() << std::endl; //Outputting the index if found
    } else {
        std::cout << "Character '" << c << "' not found in the string." << std::endl; //Outputting that the character was not found
    }

}