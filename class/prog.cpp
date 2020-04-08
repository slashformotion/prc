#include "SchoolBag.hpp"
#include "book.hpp"
#include "gravity.hpp"


#include <iostream>


void test_gravity_class()
{
     const s4prc::Gravity g0;
     auto g1 = s4prc::opposite(g0);
     std::cout << g0<< " and " << g1 << "\n";
}

void read(std::string title, const s4prc::Book &book) // ouch! a huge copy may occur here
{
  std::cout << title << ": " << book.word_count() << " words, "
                             << book.letter_count() << " letters\n";
  if(book.word_count())
  {
    std::cout << "    " << book.words().front() << " ... "
                        << book.words().back() << '\n';
  }
}

/*void test_Book()
{
     std::cout <<"~~~ begin : " << __func__ << "() ~~~\n";
     s4prc::Book b0{10'000,200};
     s4prc::Book english{{"one", "two",   "three",  "four",    "five",
                       "six", "seven", "height", "nine",    "ten"}};
     s4prc::Book book2{std::move(b0)};
     auto b2 = std::move(b0);
     read("after init, b0", std::move(b0));
     read("after init, english", std::move(english));
     read("b2", std::move(b2));
     
     std::cout <<"~~~ end : " << __func__ << "() ~~~\n";
     
}*/

void test_Schoolbag()
{
     std::cout <<"~~~ begin : " << __func__ << "() ~~~\n";
     s4prc::Book english{{"one", "two",   "three",  "four",    "five",
                       "six", "seven", "height", "nine",    "ten"}};
     s4prc::Book italian{{"uno", "due",   "tre",    "quattro", "cinque",
                         "sei", "sette", "otto",   "nove",    "dieci"}};
     s4prc::SchoolBag bag1{std::move(english), std::move(italian)};
     s4prc::SchoolBag bag2{bag1};
     s4prc::SchoolBag bag3;
     bag3=bag2;
     
     read("english from bag1", bag1.english());
     read("italian from bag1", bag1.italian());
     read("english from bag2", bag2.english());
     read("italian from bag2", bag2.italian());
     read("english from bag3", bag3.english());
     read("italian from bag3", bag3.italian());

     std::cout <<"~~~ end : " << __func__ << "() ~~~\n";
}

int main(void){

     // test_gravity_class();
     //test_Book();
     test_Schoolbag();

     return 0;
}