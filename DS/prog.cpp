// File : prog.cpp
// Created : Saturday 11 April at 09h - 17min
// user : slash

//// PERSONAL MODULES
#include "log.hpp"




//// BUILTIN LIBS
#include <iostream>
#include <random>
#include <ctime>

using namespace std;




void test_log(){
     // initialition de l'objet log avec la date d'auhourd'hui
     s4prc::Log log_entry1 {11,4,2020};
     // on simule les données à logger avec Log.populate
     log_entry1.set_DATA(s4prc::populate(10000,100)); // Donnée couteuse à recopier (1000000 caractères)
     log_entry1.show(); // on n'utiliser pas l'opérateur << car la recopie est interdite
     // on tente de changer la date vers une date inexistante --> erreur
     log_entry1.set_DAY(-1);


}

int main(){
     srand((unsigned int)time(NULL)); // setup random

     test_log();
     
     


     return 0;
}
