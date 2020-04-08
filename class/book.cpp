//----------------------------------------------------------------------------

#include "book.hpp"
#include <random>

namespace s4prc {

Book::Book(std::vector<std::string> words)
: words_{std::move(words)}
, letter_count_{0}
{
  for(const auto &elem: words_)
  {
    letter_count_+=int(size(elem));
  }
}

Book::Book(int wordCount,
           int maxLength)
: words_{}
, letter_count_{0}
{
  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<int> lengthDistrib{1, maxLength};
  std::uniform_int_distribution<int> charDistrib{'A', 'Z'};
  words_.reserve(wordCount);
  for(int i=0; i<wordCount; ++i)
  {
    const int length=lengthDistrib(rndGen);
    std::string s;
    s.reserve(length);
    for(int j=0; j<length; ++j)
    {
      s+=char(charDistrib(rndGen));
    }
    words_.emplace_back(std::move(s));
    letter_count_+=length;
  }
}

} // namespace s4prc

//----------------------------------------------------------------------------