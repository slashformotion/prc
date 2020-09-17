// File : prog.cpp
// Created : Wednesday 06 May at 15h - 44min
// user : slash

//// PERSONAL MODULES
#include "lambda.hpp"



//// BUILTIN LIBS
#include <iostream>



int main(){
     const auto test = [&](const auto &a, const auto &b)
     {
          return a>b;
     };

     return 0;
}
