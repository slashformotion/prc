#include "gravity.hpp"
#include <cmath>

namespace s4prc
{
    Gravity::Gravity(double x,
                     double y,
                     double z)
    : Gravity{}
    {
        if(const double sqrMag=x*x+y*y+z*z; // square magnitude of input vector
            sqrMag!=0.0) // overwrite default values only if input vector is not null
        {
            const double factor=magnitude/std::sqrt(sqrMag);
            xyz={x*factor, y*factor, z*factor}; // adjust magnitude
        }
    }


    // std::ostream & operator<<(std::ostream &output,
    //                           const Gravity &g)
    // {
    //     output << "{"  << g.xyz[0]
    //                     << ", " << g.xyz[1]
    //                     << ", " << g.xyz[2] << "}";
    //     return  output;
    // }

    

} // namespace s4prc
