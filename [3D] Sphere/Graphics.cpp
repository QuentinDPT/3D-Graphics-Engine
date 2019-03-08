#include "Graphics.hpp"
#include "easysdl.hpp"

#include <stdio.h>
#include <stdlib.h>

void addBlock(Graphics3D *graphics, BLOCK *block, POINT2D){

}

void addChunk(Graphics3D *graphics, CHUNK *chunk){
    for(int i(0); i<chunkSizeX; i++){


    }
}

void graphicsInitialisationGame(Graphics3D *graphics, GAME *game){
    for(int i(0); i<nbChunkX; i++){
        for(int j(0); j<nbChunkY; j++){
            addChunk(graphics,&game->terrain[i][j]) ;
        }
    }
}

void drawGame(Graphics3D *graphics, GAME *game){

    graphics->refresh() ;

}

void drawPauseScreen(GAME *game, Graphics3D *env){

    trace_rectangle_plein(0,0,winLength,winWidth,100,100,100) ;

    char *distance ;
    char *angleX ;
    char *angleY ;
    itoa(env->m_mark.distance,distance,10) ;
    itoa(env->camera.direction.angleX,angleX,10) ;
    itoa(env->camera.direction.angleZ,angleY,10) ;

    trace_texte("distance :","font.TTF",50,0,0,255,255,255) ;
    trace_texte(distance,"font.TTF",50,300,0,255,255,255) ;
    trace_texte("angleX :","font.TTF",50,0,80,255,255,255) ;
    trace_texte(angleX,"font.TTF",50,300,80,255,255,255) ;
    trace_texte("angleZ :","font.TTF",50,0,160,255,255,255) ;
    trace_texte(angleY,"font.TTF",50,300,160,255,255,255) ;
    trace_texte("Retour","font.TTF",50,0,240,255,255,255) ;

    mise_a_jour() ;
}
