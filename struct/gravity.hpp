#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include <array>

namespace s4prc
{
    struct Gravity
    {
    static constexpr double magnitude{9.81}; // Gravity-specific constant

    Gravity() // default constructor
    : xyz{{0.0, 0.0, -magnitude}}
    {
    }

    Gravity(double in_x, double in_y, double in_z);

    std::array<double, 3> xyz; // data member
    };

    // std::ostream & operator<<(std::ostream &output,
    //                           const Gravity &g);
}

#endif