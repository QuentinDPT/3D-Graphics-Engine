#ifndef GRAPHICS_HPP_INCLUDED
#define GRAPHICS_HPP_INCLUDED

/// LIBRARIES FOR GRAPHICAL STUFF
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


#ifndef DEFAULT_RENDERER
#define DEFAULT_RENDERER SDL_RENDERER_SOFTWARE
#endif // DEFAULT_BG_COLOR


typedef struct{
    unsigned int x, y ;
}SDL_UPOINT ;

typedef struct{
    unsigned int length, height ;
}SDL_USIZE ;

typedef struct{
    unsigned char r, g, b, a ;
} SDL_COLOR, *SDL_PTCOLOR ;

#endif // GRAPHICS_HPP_INCLUDED
