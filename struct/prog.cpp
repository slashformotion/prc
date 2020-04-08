#include "gravity.hpp"
#include "init.hpp"

#include <string>
#include <iostream>
#include <cmath>

void test_init()
{
    auto in1 = s4prc::Init3{1.25,6,"Voila"} ;
    std::cout << "double : " << in1.d << " int : " << in1.i << " string : " << in1.s << "\n";
}

double magnitude(const s4prc::Gravity &g)
{
     return std::sqrt(g.xyz[0]*g.xyz[0]+g.xyz[1]*g.xyz[1]+g.xyz[2]*g.xyz[2]);
}
void test_gravity_struct()
{
     s4prc::Gravity grav1{20,20,20};
     //std::cout << grav1 << "\n";
     std::cout << magnitude(grav1)<< "   "<< grav1.xyz[1] << "\n";
}



int main(void){

     //test_init();
     test_gravity_struct();


     return 0;
}