#include "strVec.hpp"
#include <vector>
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

    vector<StrVec> changeByVal(vector<StrVec> sv, std::string s, char c)
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


    void changeByRef(vector<StrVec> &sv, std::string s, char c)
    {
        std::cout << "~~~~ enter " << __func__ << "() ~~~~\n";
        sv.emplace_back(std::move(s));
        for(auto &elem: sv)
        {
            elem+=c;
        }
        std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
    }

    std::tuple<vector<std::string>, vector<std::string>,int>  manyResults(const vector<StrVec> &sv)
    {
        std::cout << "~~~~ enter " << __func__ << "() ~~~~\n";
        vector<std::string> even, odd;
        int length=0, count=0;
        for(const auto &elem: sv)
        {
            (count++%2 ? odd : even)+=elem;
            length+=int(size(elem));
        }
        std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
        return {even, odd, length}; // !!! copies involved !!! (will be fixed later)
    }
}