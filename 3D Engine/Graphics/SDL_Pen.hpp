#ifndef SDL_PEN_HPP
#define SDL_PEN_HPP

#include "Graphics.hpp"

#define DEFAULT_PEN_COLOR (SDL_COLOR){255,255,255,255}

class SDL_Pen
{
    public:
        SDL_Pen() ;
        SDL_Pen(SDL_COLOR color) ;
        SDL_Pen(unsigned char r, unsigned char g, unsigned char b) ;
        SDL_Pen(unsigned char r, unsigned char g, unsigned char b, unsigned char a) ;
        SDL_Pen(const SDL_Pen &cpy) ;

        virtual ~SDL_Pen() ;

        SDL_COLOR color ;

    protected:

    private:

};

#endif // SDL_PEN_HPP
