//----------------------------------------------------------------------------

#ifndef S4PRC_NOISY_HPP
#define S4PRC_NOISY_HPP

#include <iostream>
#include <string>
#include <vector>

namespace s4prc {

inline
std::ostream &
operator<<(std::ostream &output,
           const std::string &s) // display string within quotes
{
  using std::operator<<;
  output << '"';
  if(const auto sz=size(s); sz>20) // prevent from using too much space
  {
    output << s.substr(0, 10) << "..." << s.substr(sz-10);
  }
  else
  {
    output << s;
  }
  return output << '"';
}

template<typename E>
inline
std::ostream &
operator<<(std::ostream &output,
           const std::vector<E> &v) // display vector within braces
{
  output << '{';
  if(const auto sz=size(v); sz>4) // prevent from using too much space
  {
    output << v[0] << ',' << v[1] << ",...," << v[sz-2] << ',' << v[sz-1];
  }
  else
  {
    int count=0;
    for(const auto &elem: v)
    {
      if(count++)
      {
        output << ',';
      }
      output << elem;
    }
  }
  return output << '}';
}

template<typename T>
struct Noisy : T
{
  Noisy()
  : T{}
  {
    std::cout << "construct " << *this
              << " from nothing\n";
  }

  Noisy(const T &t)
  : T{t}
  {
    std::cout << "copy-construct " << *this
              << "\n   ... from " << t << '\n';
  }

  Noisy(T &&t)
  : T{std::move(t)}
  {
    std::cout << "move-construct " << *this
              << "\n   ... from (moved) " << t << '\n';
  }

  Noisy(const Noisy &n)
  : T{static_cast<const T &>(n)}
  {
    std::cout << "copy-construct " << *this
              << "\n   ... from " << n << '\n';
  }

  Noisy(Noisy &&n) noexcept
  : T{std::move(static_cast<T &&>(n))}
  {
    std::cout << "move-construct " << *this
              << "\n   ... from (moved) " << n << '\n';
  }

  Noisy &
  operator=(const T &t)
  {
    T::operator=(t);
    std::cout << "copy-assign " << *this
              << "\n   ... from " << t << '\n';
    return *this;
  }

  Noisy &
  operator=(T &&t)
  {
    T::operator=(std::move(t));
    std::cout << "move-assign " << *this
              << "\n   ... from (moved) " << t << '\n';
    return *this;
  }

  Noisy &
  operator=(const Noisy &n)
  {
    T::operator=(static_cast<const T &>(n));
    std::cout << "copy-assign " << *this
              << "\n   ... from " << n << '\n';
    return *this;
  }

  Noisy &
  operator=(Noisy &&n) noexcept
  {
    T::operator=(std::move(static_cast<T &&>(n)));
    std::cout << "move-assign " << *this
              << "\n   ... from (moved) " << n << '\n';
    return *this;
  }

  ~Noisy()
  {
    std::cout << "destroy " << *this << '\n';
  }

  friend
  std::ostream &
  operator<<(std::ostream &output,
             const Noisy &n)
  {
    return output << "Noisy@" << &n << ":" << static_cast<const T &>(n);
  }
};

} // namespace s4prc

#endif // S4PRC_NOISY_HPP

//----------------------------------------------------------------------------