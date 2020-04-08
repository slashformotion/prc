//----------------------------------------------------------------------------

#ifndef S4PRC_BOOK_HPP
#define S4PRC_BOOK_HPP

#include <vector>
#include <string>

namespace s4prc {

class Book
{
public:

  Book(std::vector<std::string> words={});

  Book(int wordCount,
       int maxLength);

#if 1

  //-- disable copy --
  //Book(const Book &) =delete;
  //Book & operator=(const Book &) =delete;

  //-- default move is suitable --
  Book(Book &&) =default;
  Book & operator=(Book &&) =default;

  //-- default destruction is suitable --
  ~Book() =default;

#endif

  int
  word_count() const
  {
    return int(size(words_));
  }

  int
  letter_count() const
  {
    return letter_count_;
  }

  const std::vector<std::string> &
  words() const
  {
    return words_;
  }

private:
  std::vector<std::string> words_;
  int letter_count_;
};

} // namespace s4prc

#endif // S4PRC_BOOK_HPP

//----------------------------------------------------------------------------