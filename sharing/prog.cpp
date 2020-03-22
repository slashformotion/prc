#include "strVec.hpp"
#include "fnct_call.hpp"
#include "noisy.hpp"


#include <iostream>

#define  endl "\n"

using NoisyStr = s4prc::Noisy<std::string>;

void
test_construct_destroy()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  NoisyStr n1;
  NoisyStr n2{"DATA"};
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << '\n';
  std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
}
 

void
test_copy()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  NoisyStr n1;
  NoisyStr n2{"DATA"};
  NoisyStr n3{n2};
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  n1=n3;
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  n1=NoisyStr{"NEW DATA"};
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
}

void
test_move()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  NoisyStr n1;
  NoisyStr n2{"DATA"};
  NoisyStr n3{std::move(n2)};
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  n1=std::move(n3);
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  n1=NoisyStr{"NEW DATA"};
  std::cout << "  n1=" << n1 << "\n  n2=" << n2 << "\n  n3=" << n3 << '\n';
  std::cout << "~~~~ leave " << __func__ << "()   ~~~~\n";
}

void
test_return()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  NoisyStr n{s4prc::produce("Ciao")};
  std::cout << "  n=" << n << '\n';
  n=s4prc::produce("Hi");
  std::cout << "  n=" << n << '\n';
  std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
}

void
test_params()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  NoisyStr n{"DATA"};
  s4prc::consume(n);
  std::cout << "...\n";
  s4prc::consume(NoisyStr{"TEMPORARY"});
  std::cout << "...\n";
  s4prc::consume(std::move(n));
  std::cout << "~~~~ leave " << __func__ << "() ~~~~\n";
}

void
test_noisy()
{
  std::cout << "\n~~~~ enter " << __func__ << "() ~~~~\n";
  s4prc::Noisy<s4prc::StrVec> big{s4prc::makeStrVec(10'000)};
  std::cout << ">>> big=" << big << '\n';

  big = s4prc::changeByVal(big, std::to_string(size(big))+'!', 'A');
  std::cout << ">>> big=" << big << '\n';

  s4prc::changeByRef(big, std::to_string(size(big))+'!', 'C');
  std::cout << ">>> big=" << big << '\n';
  std::cout << "~~~~ leave " << __func__ << "() ~~~~"<< endl;
}

int main(void){
    //test_construct_destroy();
    //test_copy();
    //test_return();
    //  test_params();
    test_noisy(); 
     return 0; 
} 