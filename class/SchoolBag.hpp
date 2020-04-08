#ifndef SCHOOLBAG_HPP
#define SCHOOLBAG_HPP

#include "book.hpp"

namespace s4prc
{
    class SchoolBag
    {
        public:

            SchoolBag(Book english={}, Book italian={})
            : english_{std::move(english)} , italian_{std::move(italian)} // NOTE: déplacement car copie interdite 
            {
                // nothing more to be done
            }

            const Book & english() const
            {
                return english_;
            }

            const Book & italian() const
            {
                return italian_;
            }

        private:
            Book english_;
            Book italian_;
    };
} // namespace s4prc


#endif