#ifndef MATHS_HPP_INCLUDED
#define MATHS_HPP_INCLUDED

#include "Structures.hpp"

VECTOR3D getVect(POINT3D a, POINT3D b) ;


int scalar(VECTOR3D a, VECTOR3D b) ;


int angle(VECTOR3D a, VECTOR3D b) ;


VECTOR3D vectorial(VECTOR3D a, VECTOR3D b) ;


int distance(POINT3D a, POINT3D b) ;


int abs(int a) ;


POINT3D getPoint(int x, int y, int z) ;

#endif // MATHS_HPP_INCLUDED
