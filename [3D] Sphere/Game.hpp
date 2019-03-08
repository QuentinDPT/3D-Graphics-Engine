#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Structures.hpp"
#include "easysdl.hpp"
#include "Graphics.hpp"

void mainGame() ;
void initializeGame(GAME *game) ;
int pauseScreen(GAME *game, Graphics3D *env) ;

#endif // GAME_HPP_INCLUDED
