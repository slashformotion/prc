#ifndef INIT_HPP
#define INIT_HPP

#include <string>


namespace s4prc{


    struct Init0
    {
        double d;
        int i;
        std::string s;
    };


    struct Init2
    {
        double d;
        int i;
        std::string s;

        Init2() ///// constructeur : fonction ayant le même nom que cette structure et n'exprimant aucun type de retour    ce constructeur n'attend aucun paramètre : c'est donc un constructeur par défaut
        : d{98.76} , i{54}, s{"Init2"} // member initialiser list
        {
            // (empty) constructor body
        }
    };

    struct Init3
    {
        double d;
        int i;
        std::string s;

        Init3(double in_d, int in_i, std::string in_s) ///// constructeur : fonction ayant le même nom que cette structure et n'exprimant aucun type de retour    ce constructeur n'attend aucun paramètre : c'est donc un constructeur par défaut
        : d{in_d} , i{in_i}, s{std::move(in_s)} // member initialiser list
        {
            // (empty) constructor body
        }

        Init3()
        : Init3{34.56, 78, "Init3"} // delegating constructor (by default)
        {
            // (empty) constructor body
        }
    };
}
#endif



 