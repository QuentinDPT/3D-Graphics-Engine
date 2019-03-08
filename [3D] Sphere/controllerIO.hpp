#ifndef CONTROLLERIO_H
#define CONTROLLERIO_H

#include "Structures.hpp"
#include "Graphics3D.hpp"

int winMessage(GAME *game, POINT2D *focus) ;
void loadChunk(CHUNK *chunk, char mapName[]) ;

void _mouseEvent(GAME *game, int message, POINT2D *focus) ;
void _keyEvent(GAME *game, char key) ;

void displayCursor(bool) ;

void setWinCursor(POINT2D point) ;
void setWinCursor(int x, int y) ;

#endif // CONTROLLERIO_H

