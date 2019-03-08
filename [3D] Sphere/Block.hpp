#ifndef BLOCK_H
#define BLOCK_H

#include "Graphics3D.hpp"
#include "Structures.hpp"

void blockInitializer(BLOCK *block) ;
void paintBlock(BLOCK *block, COLOR color) ;
void paintFace(BLOCK *block, int face, COLOR color) ;

#endif // BLOCK_H
