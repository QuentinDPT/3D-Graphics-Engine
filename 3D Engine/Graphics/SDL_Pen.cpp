#include "SDL_Pen.hpp"

SDL_Pen::SDL_Pen() :
    SDL_Pen(DEFAULT_PEN_COLOR)
{}

SDL_Pen::SDL_Pen(SDL_COLOR col) :
    color(col)
{}

SDL_Pen::SDL_Pen(unsigned char r, unsigned char g, unsigned char b) :
    color((SDL_COLOR){r,g,b,255})
{}

SDL_Pen::SDL_Pen(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
    color((SDL_COLOR){r,g,b,a})
{}


SDL_Pen::~SDL_Pen()
{}


