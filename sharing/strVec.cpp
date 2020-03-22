#include "strVec.hpp"
#include "noisy.hpp"
#include <string>
namespace s4prc{

    StrVec makeStrVec(int count)
    {
        StrVec result;
        for(int i=0; i<count; ++i)
        {
            result.emplace_back("str"+std::to_string(i));
        }
        return result;
    }

    Noisy<StrVec> changeByVal(Noisy<StrVec> sv, std::string s, char c)
    {
        std::cout << "~~~~ enter " << __func__ << "() ~~~~\n";
        sv.emplace_back(std::move(s));
        for(auto &elem: sv)
        {
            elem+=c;
        }
        std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
        return sv;
    }


    void changeByRef(Noisy<StrVec> &sv, std::string s, char c)
    {
        std::cout << "~~~~ enter " << __func__ << "() ~~~~\n";
        sv.emplace_back(std::move(s));
        for(auto &elem: sv)
        {
            elem+=c;
        }
        std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
    }
}