#include "sensors.hpp"

#include <tuple>

using namespace std;
namespace sens
{
    tuple<bool, double> Sensor::extract()
    {
        double value=0.0;
        const bool available=bool(input_ >> value); // try to read from file
        if(available)
        {
            filter_.sample(value); // consider this new raw value
            value=filter_.mean();  // provide a filtered value
        }
        return make_tuple(available, value);
    }
} // namespace sens


