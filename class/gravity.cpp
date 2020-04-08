#include "gravity.hpp"
#include <cmath>
#include <iostream>

namespace s4prc
{
    
    /// METHODS ///
    Gravity::Gravity(double x,
                 double y,
                 double z)
    : Gravity{} // delegating constructor
    {
        if(const double sqrMag=x*x+y*y+z*z; // square magnitude of input vector
            sqrMag!=0.0) // overwrite default values only if input vector is not null
        {
            const double factor=magnitude/std::sqrt(sqrMag);
            xyz_={x*factor, y*factor, z*factor}; // adjust magnitude
        }
    }
    void
    Gravity::set_(double value, double &changed)
    {
        value=std::max(-magnitude, std::min(magnitude, value));
        changed=value;
        double sqrRemaining=0.0;
        for(const auto &elem: xyz_)
        {
            if(&elem!=&changed)
            {
            sqrRemaining+=elem*elem;
            }
        }
        if(sqrRemaining!=0.0)
        {
            const double sqrExpected=magnitude*magnitude-value*value;
            const double factor=std::sqrt(sqrExpected/sqrRemaining);
            for(auto &elem: xyz_)
            {
            if(&elem!=&changed)
            {
                elem*=factor;
            }
            }
        }
    }   


    /// NON-METHODS ///
    std::ostream & operator<<(std::ostream &output, const Gravity &g)
    {
        output << "{" << g.x() <<", "<< g.y() <<", "<< g.z() <<"}";
        return output;
    }
    
    Gravity opposite(const Gravity &g){
        return Gravity{-g.x(), -g.y(), -g.z()};
    }
    
    double magnitude(Gravity &g)
    {
        return std::sqrt(g.x()*g.x()+g.y()*g.y()+g.z()*g.z());
    }
} // namespace s4prc
