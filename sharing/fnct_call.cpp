#include "fnct_call.hpp"


namespace s4prc{
    void consume(Noisy<std::string> param)
    {
    std::cout << "~~~~ " << __func__ << '(' << param << ") ~~~~\n";
    }
}