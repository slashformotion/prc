//----------------------------------------------------------------------------

#ifndef S4PRC_StrVecSilent_HPP
#define S4PRC_StrVecSilent_HPP

#include <vector>
#include <tuple>
#include <string>

namespace s4prc {

    using StrVecSilent = std::vector<std::string>;

    StrVecSilent
    makeStrVecSilent(int count);

    //---- vector functions ----

    vector<StrVecSilent>
    changeByVal(vector<StrVecSilent> sv,
                std::string s,
                char c);

    void
    changeByRef(vector<StrVecSilent> &sv,
                std::string s,
                char c);

    std::tuple<vector<std::string>, // even strings
            vector<std::string>, // odd strings
            int>                // total length
    manyResults(const vector<StrVecSilent> &sv);

    //---- silent functions ----

    StrVecSilent
    changeByVal(StrVecSilent sv,
                std::string s,
                char c);

    void
    changeByRef(StrVecSilent &sv,
                std::string s,
                char c);

    std::tuple<std::string, // even strings
            std::string, // odd strings
            int>         // total length
    manyResults(const StrVecSilent &sv);

    std::tuple<vector<std::string>, vector<std::string>,int> manyResults(const vector<StrVecSilent> &sv);

} // namespace s4prc

#endif // S4PRC_StrVecSilent_HPP

//----------------------------------------------------------------------------