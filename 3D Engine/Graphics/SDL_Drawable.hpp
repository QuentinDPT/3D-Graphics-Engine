#ifndef SDL_DRAWABLE_HPP
#define SDL_DRAWABLE_HPP

#include "Graphics.hpp"
#include "SDL_Pen.hpp"

class SDL_Drawable
{
    public:
        SDL_Drawable();
        virtual ~SDL_Drawable();

        virtual void draw() = 0 ;

    protected:
        SDL_UPOINT m_location ;
        SDL_Pen    m_pen ;

    private:
};

#endif // SDL_DRAWABLE_HPP
