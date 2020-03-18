#ifndef VECT3D_HPP
#define VECT3D_HPP
#include <iostream>
struct vect3D{
    double x,y,z;
};

inline vect3D operator+(vect3D v1, vect3D v2){
    const vect3D result = {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
    return result;
}

inline void display(vect3D v1){
    std::cout << "x : " << v1.x << "y : " << v1.y << "z : " << v1.z << "\n";
 }




#endif //VECT3D_HPP