#include "module.hpp"


#include <string> 
#include <iostream>






int main(){
    std::string msg="Hi there!";
    std::cout << enumerateChars(msg, '.') << std::endl;

    
    if(auto pos = msg.find('t'); pos!=msg.npos)
    {
        std::cout<< "charactère found at : " << pos << " position and the character is : " << msg[pos] << "\n";
    }

    return 0;
}

