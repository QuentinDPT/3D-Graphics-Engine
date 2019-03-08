#ifndef GRAPHICS3D_H
#define GRAPHICS3D_H

#include "Structures.hpp"
#include "controllerIO.hpp"

#include <vector>

class Graphics3D
{
    public:
        Graphics3D();
        virtual ~Graphics3D();

        void refresh() ;            // refresh all the graphics

        void setIso() ;

        std::vector <POINT3D> points ;
        std::vector <SURFACE> surface ;
        std::vector <SEGMENT> segment ;

        bool displayMark ;          // true if we must display the mark
        bool displayHitbox ;        // true if we must display the hitbox and the lines
        bool displaySurfaces ;      // true if we must refresh the surfaces
        bool displayPoint ;
        bool displaySegment ;

        void setDistance(int dist) ;

        bool lightEffects ;

        CAMERA camera ;             // contain all the camera variables

        MARK m_mark ;               //the mark on the terrain, alway hide

    protected:
    private:

        void _refresh() ;           // internal refresh (variables ...)
        void _mark() ;              // refresh the mark
        void _hitbox() ;            // refresh the hitbox and all the lines
        void _surfaces() ;          // refresh the surfaces

        void _points() ;
        void _segments() ;

        unsigned char m_minimumSurfaceLight ;

        POINT2D m_axeX ;
        POINT2D m_axeY ;
        POINT2D m_axeZ ;

        MARK m_screenMark ;         //the mark on the middle of the screen

};

#endif // GRAPHICS3D_H
