#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <string>
#include <fstream>
#include <tuple>


#include "rollingMean.hpp"

using namespace std;

namespace sens
{
    class Sensor
    {
        public:


            //-- disable copy --
            inline Sensor(const Sensor &rhs)
            : Sensor(rhs.device_)
            {

            }
            inline Sensor & operator=(const Sensor &rhs)
            {
                device_=rhs.device_;
                input_=std::ifstream{device_};
                filter_=moy::RollingMean{10};
                return *this;
            }

            //-- default move is suitable --
            Sensor(Sensor &&) =default;
            Sensor & operator=(Sensor &&) =default;

            //-- default destruction is suitable --
            ~Sensor() =default;

            Sensor(string s)
            : device_{s}, input_{device_}, filter_{10}
            {
                //nothing
            }


            /// METHODS
            inline string& device() { return device_; }

            tuple<bool, double> extract();

        private:

        string device_;
        ifstream input_;
        moy::RollingMean filter_;

        

    };
} // namespace sens


#endif