#include "SchoolBag.hpp"

namespace s4prc
{
    SchoolBag::SchoolBag(const SchoolBag &rhs)
    : english_{rhs.english_.words()}
    , italian_{rhs.italian_.words()}
    {
    // nothing more to be done
    }

    SchoolBag& SchoolBag::operator=(const SchoolBag &rhs)
    {
        this->english_=Book{rhs.english_.words()};
        this->italian_=Book{rhs.italian_.words()};
        return *this;
    }
} // namespace s4prc

