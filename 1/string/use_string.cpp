#include "use_string.hpp"
#include <string>

namespace s4prc{
    std::string enumerateChars(std::string txt, char separator='|'){
        std::string result; // default initialisation yields an empty string
        for(const char &c: txt) // for each character in a string
        {
            if(!empty(result)) // test whether a string is empty or not
            {
                result+=separator; // append a character to a string
            }
            result+=c; // append a character to a string
        }
        return result; // a string is safely transmitted as a return value
    }
}