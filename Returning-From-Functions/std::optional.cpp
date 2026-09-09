/* Using std::optional in C++ */

#include <iostream>
#include <optional>


int main(){

    //Declare and initialize

    std::optional<int> opt1{42}; //Optional with a value
    std::optional<std::string> opt2{"Hello, World!"}; //Optional with a value
    std::optional<double> opt3 {3.1415}; //Optional with a value
    std::optional<char> opt4{'f' }; //Optional with a value

    //Declare and empty initialize


    //std::nullopt is the null or zero equivalent for std::optional
    std::optional<int> opt5; //Empty optional
    std::optional<std::string> opt6; //Empty optional
    std::optional<double> opt7; //Empty optional
    //Initialize with std::nullopt
    std::optional<char> opt8{std::nullopt}; //Empty optional

    //read the values of the optional variables

    std::cout << "opt1 : " << opt1.value() << std::endl; //Outputting the value of opt1 
    std::cout << "opt2 : " << opt2.value() << std::endl; //Outputting the value of opt2
    std::cout << "opt3 : " << opt3.value() << std::endl; //Outputting the value of opt3
    std::cout << "opt4 : " << opt4.value() << std::endl; //Outputting the value of opt4

    //Write the values of the optional variables

    opt5 = 100; //Assigning a value to opt5
    opt6 = "Optional String"; //Assigning a value to opt6

    std::cout << "opt5 : " << opt5.value() << std::endl; //Outputting the value of opt5
    std::cout << "opt6 : " << opt6.value() << std::endl; //Outputting the value of opt6

    //Reading empty optional variables

    if(opt7.has_value()){
        std::cout << "opt7 has a value: " << opt7.value() << std::endl; //Outputting the value of opt7
    } else {
        std::cout << "opt7 is empty." << std::endl; //Outputting that opt7 is empty
    }

    if(opt8.has_value()){
        std::cout << "opt8 has a value: " << opt8.value() << std::endl; //Outputting the value of opt8
    } else {
        std::cout << "opt8 is empty." << std::endl; //Outputting that opt8 is empty
    }

    return 0;

}