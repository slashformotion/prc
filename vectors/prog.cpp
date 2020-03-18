#include "vectors.hpp"

#include <vector>
#include <iostream>
void test_vector(void)
{
    std::cout << "-----begining of " << __func__ << "()-----\n\n"; 
    std::vector<double> crescendo = {0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    afficher(crescendo);
    std::cout << crescendo[2] << "\n";
    std::cout << size(crescendo) << "\n";
    if (empty(crescendo))
    {
        std::cout << "le tableau dynamique est vide\n";
    }
    else
    {
        std::cout << "le tableau dynamique n'est pas vide\n";
        
    }

    std::cout << "le dernier element est : " << crescendo.back() << "\n";
    crescendo.pop_back();
    std::cout << "le (nouveau) dernier element est : " << crescendo.back() << "\n";
    crescendo.emplace_back(10.1);
    std::cout << "le (nouveau) (nouveau) dernier element est : " << crescendo.back() << "\n";
    std::cout << "-----ending of " << __func__ << "()-----\n\n"; 
    
}

int main()
{
    test_vector();
    
    return 0;
}