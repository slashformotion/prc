#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include <iostream>
#include <array>

namespace s4prc
{
    class Gravity
    {
        public:
        
        Gravity()
        : xyz_{{0.0, 0.0, -magnitude}}
        {
           // (empty) body constructor
        }

        static constexpr double magnitude{9.81}; // Gravity-specific constant

        

        inline double x() const { return xyz_[0]; } // xyz_ raccourci pour this->xyz_ et ici "const" dit que le pointer vers l'objet est constant
        inline double y() const { return xyz_[1]; }
        inline double z() const { return xyz_[2]; }

        Gravity(double x,
          double y,
          double z);
        inline void setX(double x) 
        {
            set_(x,xyz_[0]);
        }

        inline void setY(double y) 
        {
            set_(y,xyz_[1]);
        }

        inline void setZ(double z) 
        {
            set_(z,xyz_[2]);
        }

        

        private:
        void set_(double value, double &changed);
        
        std::array<double, 3> xyz_;


        


    };

    
    double magnitude(const Gravity &g);
    Gravity opposite(const Gravity &g);


    /// OPERATORS /// 
    std::ostream & operator<<(std::ostream & output,
                              const Gravity &g);

    

}

#endif