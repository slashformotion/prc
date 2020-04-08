#ifndef SCHOOLBAG_HPP
#define SCHOOLBAG_HPP

#include "book.hpp"

namespace s4prc
{
    class SchoolBag
    {
        public:

            //-- provide copy --
            SchoolBag(const SchoolBag &rhs);
            SchoolBag& operator=(const SchoolBag &rhs);

            //-- default move is suitable --
            SchoolBag(SchoolBag &&) =default;
            SchoolBag & operator=(SchoolBag &&) =default;

            //-- default destruction is suitable --
            ~SchoolBag() =default;

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