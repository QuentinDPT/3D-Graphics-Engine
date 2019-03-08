#include "Graphics3D.hpp"
#include "easysdl.hpp"

#include <math.h>
#include "Maths.hpp"
#include <iostream>

Graphics3D::Graphics3D()
{
    displayMark = true ;
    displayHitbox = true ;
    displaySurfaces = true ;
    displayPoint = true ;
    displaySegment = true ;

    lightEffects = true ;

    m_mark.distance = 30 ;
    m_mark.origin.x = winLength/2 ;
    m_mark.origin.y = winWidth/2 ;

    camera.position.x = 0 ;
    camera.position.y = 0 ;
    camera.position.z = 0 ;

    setIso() ;


    //ctor
}

Graphics3D::~Graphics3D()
{
    //dtor
}

void Graphics3D::refresh(){
    trace_rectangle_plein(0,0,winLength,winWidth,0,0,0) ;

    _refresh() ;
    if(displayHitbox)
        _hitbox() ;
    if(displaySurfaces)
        _surfaces() ;
    if(displaySegment)
        _segments() ;
    if(displayMark)
        _mark() ;
    if(displayPoint)
        _points() ;
}

void Graphics3D::setIso(){
    camera.direction.angleX = 135 ;
    camera.direction.angleZ = 45 ;
}

void Graphics3D::_refresh(){

    if(camera.direction.angleX<-180 || camera.direction.angleX>=180)
        camera.direction.angleX = (camera.direction.angleX+180)%360-180 ;
    if(camera.direction.angleZ<-180 || camera.direction.angleZ>=180)
        camera.direction.angleZ = (camera.direction.angleZ+180)%360-180 ;

    int distanceFact (2);

    camera.position.x = 0 ;
    camera.position.y = 0 ;
    camera.position.z = 0 ;

    m_axeZ.x = 0 ;
    m_axeZ.y = cos(PI*(double(camera.direction.angleZ)/180))*m_mark.distance ;

    m_axeX.x = sin(double(PI)*(double(camera.direction.angleX)/180)+PI*0.5)*m_mark.distance ;
    m_axeX.y = -cos(double(PI)*(double(camera.direction.angleX)/180)+PI*0.5)*m_mark.distance*(double(m_axeZ.y)/double(m_mark.distance)) ;

    m_axeY.x = sin(double(PI)*(double(camera.direction.angleX)/180))*m_mark.distance ;
    m_axeY.y = -cos(double(PI)*(double(camera.direction.angleX)/180))*m_mark.distance*(double(m_axeZ.y)/double(m_mark.distance)) ;

    m_axeZ.y = -m_mark.distance ;
    m_axeZ.y -= cos(PI*(double(camera.direction.angleZ)/180))*m_mark.distance ;

}

void Graphics3D::_hitbox(){



}

void Graphics3D::_surfaces(){

    int _angle ;

    for(int i(0) ; i< surface.size() ; i++){
        _angle = angle(getVect(getPoint(points[surface[i].pointIDA].x,points[surface[i].pointIDA].y,points[surface[i].pointIDA].z),getPoint(camera.position.x,camera.position.y,camera.position.z)),surface[i].normalVect) ;
        if(_angle < 90)
            trace_triangle_plein(m_axeX.x*points[surface[i].pointIDA].x+m_axeY.x*points[surface[i].pointIDA].y+m_axeZ.x*points[surface[i].pointIDA].z+m_mark.origin.x,
                                 m_axeX.y*points[surface[i].pointIDA].y+m_axeY.y*points[surface[i].pointIDA].z+m_axeZ.y*points[surface[i].pointIDA].z+m_mark.origin.y,
                                 m_axeX.x*points[surface[i].pointIDB].x+m_axeY.x*points[surface[i].pointIDB].y+m_axeZ.x*points[surface[i].pointIDB].z+m_mark.origin.x,
                                 m_axeX.y*points[surface[i].pointIDB].y+m_axeY.y*points[surface[i].pointIDB].z+m_axeZ.y*points[surface[i].pointIDB].z+m_mark.origin.y,
                                 m_axeX.x*points[surface[i].pointIDC].x+m_axeY.x*points[surface[i].pointIDC].y+m_axeZ.x*points[surface[i].pointIDC].z+m_mark.origin.x,
                                 m_axeX.y*points[surface[i].pointIDC].y+m_axeY.y*points[surface[i].pointIDC].z+m_axeZ.y*points[surface[i].pointIDC].z+m_mark.origin.y,
                                 surface[i].color.r*(double(_angle)/90),surface[i].color.g*(double(_angle)/90),surface[i].color.b*(double(_angle)/90)) ;

    }

}

void Graphics3D::_mark(){

    trace_segment(m_mark.origin.x,
                  m_mark.origin.y,
                  m_mark.origin.x+m_axeX.x*m_mark.distance,
                  m_mark.origin.y+m_axeX.y*m_mark.distance,
                  255,0,0) ;
    trace_segment(m_mark.origin.x,
                  m_mark.origin.y,
                  m_mark.origin.x+m_axeY.x*m_mark.distance,
                  m_mark.origin.y+m_axeY.y*m_mark.distance,
                  0,255,0) ;
    trace_segment(m_mark.origin.x,
                  m_mark.origin.y,
                  m_mark.origin.x+m_axeZ.x*m_mark.distance,
                  m_mark.origin.y+m_axeZ.y*m_mark.distance,
                  0,0,255) ;

}

void Graphics3D::_points(){

    for(int i(0) ; i<points.size() ; i++){

        trace_point(m_axeX.x*points[i].x+m_axeY.x*points[i].y+m_axeZ.x*points[i].z+m_mark.origin.x,
                    m_axeX.y*points[i].y+m_axeY.y*points[i].z+m_axeZ.y*points[i].z+m_mark.origin.y,
                    255,255,255) ;
    }
}

void Graphics3D::_segments(){
    for(int i(0) ; i< segment.size() ; i++){
        trace_segment(m_axeX.x*points[segment[i].pointIDA].x+m_axeY.x*points[segment[i].pointIDA].y+m_axeZ.x*points[segment[i].pointIDA].z+m_mark.origin.x,
                      m_axeX.y*points[segment[i].pointIDA].y+m_axeY.y*points[segment[i].pointIDA].z+m_axeZ.y*points[segment[i].pointIDA].z+m_mark.origin.y,
                      m_axeX.x*points[segment[i].pointIDB].x+m_axeY.x*points[segment[i].pointIDB].y+m_axeZ.x*points[segment[i].pointIDB].z+m_mark.origin.x,
                      m_axeX.y*points[segment[i].pointIDB].y+m_axeY.y*points[segment[i].pointIDB].z+m_axeZ.y*points[segment[i].pointIDB].z+m_mark.origin.y,
                      segment[i].color.r,segment[i].color.g,segment[i].color.b) ;

    }
}
