#ifndef SDL_LINE_HPP
#define SDL_LINE_HPP

#include "SDL_Drawable.hpp"

class SDL_Line : public SDL_Drawable
{
    public:
        SDL_Line();
        virtual ~SDL_Line();

        void draw() ;

    protected:

    private:
};

#endif // SDL_LINE_HPP
