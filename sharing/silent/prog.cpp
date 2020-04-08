
#include "strVec.hpp"
#include "fnct_call.hpp"



#include <iostream>






void
test_silent()
{
  std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
  using s4prc::operator<<; // compact display of StrVec and std::string
  auto big{s4prc::makeStrVec(10'000)};
  std::cout << ">>> big=" << big << '\n';
  big=s4prc::changeByVal(big, std::to_string(size(big))+'!', 'A');
  std::cout << ">>> big=" << big << '\n';
  big=s4prc::changeByVal(std::move(big), std::to_string(size(big))+'!', 'B');
  std::cout << ">>> big=" << big << '\n';
  s4prc::changeByRef(big, std::to_string(size(big))+'!', 'C');
  std::cout << ">>> big=" << big << '\n';
  auto [evenStr, oddStr, totalLength]=s4prc::manyResults(big);
  std::cout << ">>> evenStr=" << evenStr << '\n';
  std::cout << ">>> oddStr=" << oddStr << '\n';
  std::cout << ">>> totalLength=" << totalLength << '\n';
}

int main(void){
    //test_construct_destroy();
    //test_copy();
    //test_return();
    //  test_params();
    test_silent(); 
     return 0; 
} 