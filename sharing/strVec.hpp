//----------------------------------------------------------------------------

#ifndef S4PRC_STRVEC_HPP
#define S4PRC_STRVEC_HPP

#include "noisy.hpp"
#include <tuple>

namespace s4prc {

    using StrVec = std::vector<std::string>;

    StrVec
    makeStrVec(int count);

    //---- noisy functions ----

    Noisy<StrVec>
    changeByVal(Noisy<StrVec> sv,
                std::string s,
                char c);

    void
    changeByRef(Noisy<StrVec> &sv,
                std::string s,
                char c);

    std::tuple<Noisy<std::string>, // even strings
            Noisy<std::string>, // odd strings
            int>                // total length
    manyResults(const Noisy<StrVec> &sv);

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

} // namespace s4prc

#endif // S4PRC_STRVEC_HPP

//----------------------------------------------------------------------------