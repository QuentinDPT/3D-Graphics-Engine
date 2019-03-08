#ifndef SDL_SHAPE_HPP
#define SDL_SHAPE_HPP

#include "SDL_Pen.hpp"
#include "SDL_Drawable.hpp"

class SDL_Shape : public SDL_Drawable
{
    public:
        SDL_Shape();
        virtual ~SDL_Shape();

        virtual void draw() = 0 ;

    protected:
        SDL_Pen m_borderPen ;

        void   *m_points ;

    private:
};

#endif // SDL_SHAPE_HPP
