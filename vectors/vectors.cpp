#include "vectors.hpp"
#include <iostream>
#include <vector>

void dummy(void){}


void afficher(std::vector<double> to_print){
    for(const auto value : to_print){
        std::cout << value << "\n" ; 
    }
}