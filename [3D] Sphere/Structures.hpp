#ifndef STRUCTURES_HPP_INCLUDED
#define STRUCTURES_HPP_INCLUDED

#include <vector>

#define chunkSizeX 16
#define chunkSizeY 16
#define chunkSizeZ 2

#define nbChunkX 1
#define nbChunkY 1

#define ESCAPE 27
#define ENTER 13

#define PAUSE 9
#define CONTROL_UP 'Z'
#define CONTROL_DOWN 'S'
#define CONTROL_RIGHT 'D'
#define CONTROL_LEFT 'Q'

#define FPS_LIMIT 0.0001

#define SensibilityX 2
#define SensibilityY 2

#define PI 3.141592654

#define winLength 1500
#define winWidth 900

typedef enum {BLOCK_AIR,BLOCK_WHITE,BLOCK_BLUE,BLOCK_RED,BLOCK_GREEN}BLOCK_TYPE ;

enum {FACEUP,FACEDOWN,FACENORTH,FACESOUTH,FACEEAST,FACEWEST};
//enum {EXIT,MOUSEMOVE,MOUSELEFTCLICK,MOUSERIGHTCLICK,KEYDOWN};

typedef struct{
    unsigned char r ;
    unsigned char g ;
    unsigned char b ;
}COLOR ;

typedef struct{

    int x,y,z ;

}VECTOR3D ;

typedef struct{

    int x ;
    int y ;
    int z ;

}POINT3D ;

typedef struct{
    int x ;
    int y ;
}POINT2D ;

typedef struct{
    int angleX ;
    int angleZ ;
}POLAR ;

typedef struct{

    POINT3D position ;

    POLAR direction ;

}CAMERA ;

typedef struct{             // the points must be align

    int pointIDA ;
    int pointIDB ;
    int pointIDC ;
    COLOR color ;
    bool render ;
    unsigned char light ;
    VECTOR3D normalVect ;

}SURFACE ;

typedef struct{

    int pointIDA ;
    int pointIDB ;
    COLOR color ;

}SEGMENT ;

typedef struct{

    POINT3D coordonates ;
    POINT3D points[8] ;
    SURFACE faces[6] ;
    BLOCK_TYPE blockType ;

}BLOCK ;

typedef struct{
    POINT3D position ;
    BLOCK blocks[chunkSizeX][chunkSizeY][chunkSizeZ] ;
}CHUNK ;

typedef struct{
    POINT2D Xaxis ;
    POINT2D Yaxis ;
    POINT2D Zaxis ;

    POINT2D origin ;

    unsigned int distance ;
}MARK ;

typedef struct{
    CHUNK terrain[nbChunkX][nbChunkY] ;
    bool pause ;
    CAMERA *viewer ;
}GAME ;


#endif // STRUCTURES_HPP_INCLUDED
