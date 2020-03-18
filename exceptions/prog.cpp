#include <iostream>
#include <vector>
#include <string>
  
#include "args.hpp"

void afficher(std::vector<int> to_print){
    for (const int &i : to_print){
        std::cout << i << '\n';
    }
}

static_assert(sizeof(int)>=4,
              "larger integers are required in this application");


int main(int argc, char **argv){

    std::vector<std::string> args{argv, argv+argc};
    std::vector<int> values = s4prc::integersFromArgs(args);
    static_assert(sizeof(values[0])>=4, "larger integers are required as arguments");
    afficher(values);


    return 0;
}