

#include "args.hpp"


#include <vector>
#include <iostream>  
#include <exception>


namespace s4prc{
    std::vector<int> integersFromArgs(std::vector<std::string> args)
        {   
            std::vector<int> result;
            for(const auto value: args){
                try
                {
                    if(std::stoi(value)>10){
                        throw std::runtime_error{"un chiffre est plus grand que 10"};
                    }
                    result.emplace_back(std::stoi(value));

                }
                catch(const std::invalid_argument &e)
                {
                    std::cerr << "<" << value << "> does not look like an integer!\n";
                }
                catch(const std::out_of_range &e){
                    std::cerr << "<" << value << "> is to large for an integer!\n";
                }
                catch(const std::runtime_error &e){
                    std::cerr << "<" << value << "> is bigger than 10\n";
                }
            }
            
            return result;
            
    }



}
