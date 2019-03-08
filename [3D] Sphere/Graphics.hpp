#ifndef GRAPHICS_HPP_INCLUDED
#define GRAPHICS_HPP_INCLUDED

#include "Structures.hpp"
#include "Graphics3D.hpp"

void drawBlock(Graphics3D *graphics, BLOCK *block) ;
void drawChunk(Graphics3D *graphics, CHUNK *chunk) ;
void drawGame(Graphics3D *graphics, GAME *game) ;

void drawPauseScreen(GAME *game, Graphics3D *env) ;

#endif // GRAPHICS_HPP_INCLUDED
