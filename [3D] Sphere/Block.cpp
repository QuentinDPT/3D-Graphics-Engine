#include "Block.hpp"
#include "Structures.hpp"

void blockInitializer(BLOCK *block){

    block->coordonates.x = 0 ;
    block->coordonates.y = 0 ;
    block->coordonates.z = 0 ;

    block->blockType = BLOCK_WHITE ;

    COLOR colorDefault ;
    colorDefault.r = 255 ;
    colorDefault.g = 255 ;
    colorDefault.b = 255 ;

    paintBlock(block,colorDefault) ;

    block->faces[FACEDOWN] .render = true ;
    block->faces[FACEEAST] .render = true ;
    block->faces[FACENORTH].render = true ;
    block->faces[FACESOUTH].render = true ;
    block->faces[FACEUP]   .render = true ;
    block->faces[FACEWEST] .render = true ;

}

void paintBlock(BLOCK *block, COLOR color){

    paintFace(block,FACEDOWN,color) ;
    paintFace(block,FACEEAST,color) ;
    paintFace(block,FACENORTH,color) ;
    paintFace(block,FACESOUTH,color) ;
    paintFace(block,FACEUP,color) ;
    paintFace(block,FACEWEST,color) ;

}

void paintFace(BLOCK *block, int face, COLOR color){

    block->faces[face].color = color ;

}

void changeBlock(BLOCK *block, BLOCK_TYPE newType){



}
