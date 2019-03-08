#include "Maths.hpp"
#include <math.h>

VECTOR3D getVect(POINT3D a, POINT3D b){

    VECTOR3D result ;

    result.x = b.x-a.x ;
    result.y = b.y-a.y ;
    result.z = b.z-a.z ;

    return result ;
}
POINT3D getPoint(int x, int y, int z){
    POINT3D result ;

    result.x = x ;
    result.y = y ;
    result.z = z ;

    return result ;
}

int scalar(VECTOR3D a, VECTOR3D b){
    return a.x*b.x+a.y*b.y+a.z*b.z ;
}

int angle(VECTOR3D a, VECTOR3D b){
    return 0 ;
}

VECTOR3D vectorial(VECTOR3D a, VECTOR3D b){
    VECTOR3D result ;

    result.x = a.x*b.y - a.y*b.x ;
    result.y = a.y*b.z - a.z*b.y ;
    result.z = a.z*b.x - a.x*b.z ;

    return result ;
}

int distance(POINT3D a, POINT3D b){
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)+(b.z-a.z)*(b.z-a.z) ;
}

int abs(int a){
    if(a<0)
        return -a ;
    return a ;
}
