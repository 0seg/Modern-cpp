/*
    std::string Searching in C++
*/

int main(){
    //Find(1)
    //std::string::find()
    //size_type find(const basic_string& str, size_type pos = 0) const
    //Finds the starting index where the str substring is found in the string.

    std::string str1{"Hello, World!"};
    std::string str2{"or"};

    size_t found_index = str1.find(str2);
    std::cout << "Found '" << str2 << "' in str1 at index: " << found_index << std::endl;

    //Find something that doesn't exist
    str2 = "xyz";
    found_index = str1.find(str2);
    std::cout << "Found '" << str2 << "' in str1 at index: " << found_index << std::endl; 
    //Returns std::string::npos if not found


    //using std::string::npos to check if the substring was found

    std::string str3{"Hello, World!"};
    std::string str4{"World"};

    size_t found_index2 = str3.find(str4);

    if(found_index2 != std::string::npos){
        std::cout << "Found '" << str4 << "' in str3 at index: " << found_index2 << std::endl;
    } else {
        std::cout << "Substring '" << str4 << "' not found in str3." << std::endl;
    }

    //Find(2)
    //Can specify the position to start searching from
   
    std::string str5{"Hello, World!"};
    std::string str6{"o"};

    size_t found_pos = str5.find(str6);
    std::cout << "Found '" << str6 << "' in str5 at index: " << found_pos << std::endl;

    //Start searching from index 3
    found_pos = str5.find(str6, 3);
    std::cout << "Found '" << str6 << "' in str5 at index: " << found_pos << std::endl;

    //Start searching from index 6    
    found_pos = str5.find(str6, 6); 
    std::cout << "Found '" << str6 << "' in str5 at index: " << found_pos << std::endl;


    //Find(3)
    //size_type find(const CharT* s, size_type pos = 0) const;
    //Finds the first substring euqal to the character string pointed to by s, starting from position pos.

    std::string str7{"Hello, how are you?"};
    const char* substr1{"how"};

    size_t found_index3 = str7.find(substr1);

    if(found_index3 != std::string::npos){
        std::cout << "Found '" << substr1 << "' in str7 at index: " << found_index3 << std::endl;
    } else {
        std::cout << "Substring '" << substr1 << "' not found in str7." << std::endl;
    }
    

}