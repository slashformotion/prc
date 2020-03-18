#ifndef FNCT_CALL_HPP
#define FNCT_CALL_HPP
#include "noisy.hpp"
#include <string>


namespace s4prc{

    inline static Noisy<std::string>
    produce(std::string msg)
    {
    std::cout << "~~~~ enter " << __func__ << "() ~~~~\n";
    Noisy<std::string> result{msg+" via "+__func__};
    std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
    return result;
    }

    void consume(Noisy<std::string> param);

}



#endif