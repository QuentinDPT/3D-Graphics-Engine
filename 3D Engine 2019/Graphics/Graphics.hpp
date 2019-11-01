#ifndef GRAPHICS_HPP_INCLUDED
#define GRAPHICS_HPP_INCLUDED

/// LIBRARIES FOR GRAPHICAL STUFF
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <fstream>
#include <stdexcept>
#include <algorithm>

#ifndef DEFAULT_RENDERER
#define DEFAULT_RENDERER SDL_RENDERER_SOFTWARE
#endif // DEFAULT_BG_COLOR

namespace Graphics{

    class _obj_debugable{
        public :
            virtual std::ostream& print(std::ostream& os) const = 0 ;
            friend std::ostream& operator<<(std::ostream& os, const _obj_debugable& _obj){
                return _obj.print(os) ;
            };
    };

    template<typename T>
    class Point : public _obj_debugable{
        public :
            Point() : x((T)0),y((T)0) {} ;
            Point(T x, T y) : x(x), y(y) {} ;

            T x, y ;

            std::ostream& print(std::ostream& os) const{
                os << "( x=" << x << ", y=" << y << ")" ;
                return os ;
            };
    };

    template<typename T>
    class Size : public _obj_debugable{
        public :
            Size() : length((T)0),width((T)0) {} ;
            Size(T length, T width) : length(length), width(width) {} ;

            T length, width ;

            std::ostream& print(std::ostream& os) const{
                os << "( length=" << length << ", width=" << width << ")" ;
                return os ;
            };
    };

    class Color : public _obj_debugable{
        public :
            Color() : r(0), g(0), b(0) {} ;
            Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {} ;
            Color(std::string hex_code){
                Color rezz = FromHex(hex_code);
                r = rezz.r ;
                g = rezz.g ;
                b = rezz.b ;
            } ;

            uint8_t r, g, b ;

            std::ostream& print(std::ostream& os) const{
                os << "( r=" << (int)r << ", g=" << (int)g << ", b=" << (int)b << ")" ;
                return os ;
            };

            static Color FromHex(std::string hex_code) {
                Color rezz ;

                hex_code.erase(std::remove(hex_code.begin(), hex_code.end(), '#'),hex_code.end()) ;

                if(hex_code.length() != 6)
                    throw std::invalid_argument("\"" + hex_code + "\" ne correspond a aucun standard de codification de couleur") ;

                rezz.r = HexToInt(hex_code[0])*16 + HexToInt(hex_code[1]) ;
                rezz.g = HexToInt(hex_code[2])*16 + HexToInt(hex_code[3]) ;
                rezz.b = HexToInt(hex_code[4])*16 + HexToInt(hex_code[5]) ;

                return rezz ;
            } ;

        private :
            static inline uint8_t HexToInt(char hex){
                return uint8_t(hex >= 'A' ? hex-'A'+10 : hex - '0') ;
            }
    };
}

#endif // GRAPHICS_HPP_INCLUDED
