#include "Chunk.hpp"
#include "Block.hpp"

void chunkInitializer(CHUNK *chunk)
{
    for(int i(0);i < chunkSizeX; i++){
        for(int j(0); j<chunkSizeY; j++){
            for(int k(0);k<chunkSizeZ; k++){
                chunk->blocks [i][j][k].blockType = BLOCK_BLUE ;

                chunk->blocks [i][j][k].faces[FACEDOWN].color.r = 255 ;
                chunk->blocks [i][j][k].faces[FACEDOWN].color.g = 255 ;
                chunk->blocks [i][j][k].faces[FACEDOWN].color.b = 255 ;

                chunk->blocks[i][j][k].coordonates.x = chunk->position.x+i ;
                chunk->blocks[i][j][k].coordonates.y = chunk->position.y+j ;
                chunk->blocks[i][j][k].coordonates.z = chunk->position.z+k ;

                if(chunk->blocks[i+1][j][k].blockType== BLOCK_BLUE){
                    chunk->blocks[i][j][k].faces[FACEEAST].render = false ;
                }
                if(chunk->blocks[i-1][j][k].blockType== BLOCK_BLUE){

                    chunk->blocks[i][j][k].faces[FACEWEST].render = false ;
                }
                if(chunk->blocks[i][j+1][k].blockType== BLOCK_BLUE){
                    chunk->blocks[i][j][k].faces[FACENORTH].render = false ;
                }
                if(chunk->blocks[i][j-1][k].blockType== BLOCK_BLUE){
                    chunk->blocks[i][j][k].faces[FACESOUTH].render = false ;
                }
                if(chunk->blocks[i][j][k+1].blockType== BLOCK_BLUE){
                    chunk->blocks[i][j][k].faces[FACEUP].render = false ;
                }
                if(chunk->blocks[i][j][k+1].blockType== BLOCK_BLUE){
                    chunk->blocks[i][j][k].faces[FACEDOWN].render = false ;
                }
            }
        }
    }
}

void refreshPosition(int x, int y){
    for(int i(0);i < chunkSizeX; i++){
        for(int j(0); j<chunkSizeY; j++){
            for(int k(0);k<chunkSizeZ; k++){/*
                blocks[i][j][k].coordonates.x = chunkPositionX+i ;
                blocks[i][j][k].coordonates.y = chunkPositionY+j ;
                blocks[i][j][k].coordonates.z = chunkPositionZ+k ;*/
            }
        }
    }
}
