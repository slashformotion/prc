//----------------------------------------------------------------------------

#ifndef S4PRC_STRVEC_HPP
#define S4PRC_STRVEC_HPP

#include <vector>
#include <tuple>

namespace s4prc {

    using StrVec = std::vector<std::string>;

    StrVec
    makeStrVec(int count);

    //---- vector functions ----

    vector<StrVec>
    changeByVal(vector<StrVec> sv,
                std::string s,
                char c);

    void
    changeByRef(vector<StrVec> &sv,
                std::string s,
                char c);

    std::tuple<vector<std::string>, // even strings
            vector<std::string>, // odd strings
            int>                // total length
    manyResults(const vector<StrVec> &sv);

    //---- silent functions ----

    StrVec
    changeByVal(StrVec sv,
                std::string s,
                char c);

    void
    changeByRef(StrVec &sv,
                std::string s,
                char c);

    std::tuple<std::string, // even strings
            std::string, // odd strings
            int>         // total length
    manyResults(const StrVec &sv);

    std::tuple<vector<std::string>, vector<std::string>,int> manyResults(const vector<StrVec> &sv);

} // namespace s4prc

#endif // S4PRC_STRVEC_HPP

//----------------------------------------------------------------------------