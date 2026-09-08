#include <iostream>


//The default type associated with enum classes with c++ is int.
enum class Month {
    Jan = 1, Feb, Mar,
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct, Nov, Dec


};


int main(){

    Month month {Month::Jan};

    std::cout << "The value of month is: " << static_cast<int>(month) << std::endl;
    //Using static_cast to convert the enum class value to its underlying integer type for output.


}