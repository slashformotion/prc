 //----------------------------------------------------------------------------

#include "3Dvect.hpp"
#include <cstdio> // standard C header-file 
#include <iostream>


int main(int argc, char **argv)
{
  vect3D v1 = {1.1,2.2,3.3}, v2 = {3.3,2.2,1.1};
  vect3D result = v1+v2;
  display(result);
  
  
  
  return 0;
}

//----------------------------------------------------------------------------
