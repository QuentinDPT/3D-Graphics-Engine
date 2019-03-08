#include "Game.hpp"
#include "controllerIO.hpp"
#include "easysdl.hpp"
#include "Graphics3D.hpp"
#include "Graphics.hpp"

#include <math.h>
#include "Maths.hpp"

#include <time.h>
#include <iostream>

void createSphere(Graphics3D *env, POINT3D origin, int rad, int latScal, int lonScal){ // latScal & lonScal in degres

    POINT3D element ;

    SEGMENT seg ;
    seg.color.r = 100 ;
    seg.color.g = 100 ;
    seg.color.b = 100 ;

    SURFACE surf ;

    surf.color.r = 255 ;
    surf.color.g = 0 ;
    surf.color.b = 0 ;

    int sizeX (360/latScal) ;
    int sizeY (360/lonScal) ;

    for(int latInd(0) ; latInd < sizeX ; latInd ++){
        for(int lonInd(0) ; lonInd < sizeY ; lonInd ++){
            element.x = origin.x + double(double(rad) * cos(double(latInd*latScal) / double(180) * 3.14159265359) * sin(double(lonInd*lonScal) / double(180) * 3.14159265359)) ;
            element.y = origin.y + double(double(rad) * sin(double(latInd*latScal) / double(180) * 3.14159265359) * sin(double(lonInd*lonScal) / double(180) * 3.14159265359)) ;
            element.z = origin.z + double(double(rad) * cos(double(lonInd*lonScal) / double(180) * 3.14159265359)) ;
            env->points.push_back(element) ;

            if(latInd>1 && lonInd>1){
                surf.pointIDA = lonInd-1 + ((latInd)*sizeX) ;
                surf.pointIDB = lonInd-1 + ((latInd-1)*sizeX) ;
                surf.pointIDC = lonInd + ((latInd-1)*sizeX) ;
                surf.normalVect = vectorial(getVect(env->points[surf.pointIDA],env->points[surf.pointIDB]),
                                            getVect(env->points[surf.pointIDB],env->points[surf.pointIDC])) ;
                env->surface.push_back(surf) ;
                surf.pointIDA = lonInd + ((latInd)*sizeX) ;
                surf.pointIDB = lonInd + ((latInd-1)*sizeX) ;
                surf.pointIDC = lonInd-1 + ((latInd)*sizeX) ;
                surf.normalVect = vectorial(getVect(env->points[surf.pointIDA],env->points[surf.pointIDB]),
                                            getVect(env->points[surf.pointIDB],env->points[surf.pointIDC])) ;
                env->surface.push_back(surf) ;

                seg.pointIDA = lonInd-1 + ((latInd)*sizeX) ;
                seg.pointIDB = lonInd + ((latInd-1)*sizeX) ;
                env->segment.push_back(seg) ;
                seg.pointIDA = lonInd-1 + ((latInd)*sizeX) ;
                seg.pointIDB = lonInd-1 + ((latInd-1)*sizeX) ;
                env->segment.push_back(seg) ;
                seg.pointIDA = lonInd + ((latInd-1)*sizeX) ;
                seg.pointIDB = lonInd-1 + ((latInd-1)*sizeX) ;
                env->segment.push_back(seg) ;
                seg.pointIDA = lonInd + ((latInd)*sizeX) ;
                seg.pointIDB = lonInd + ((latInd-1)*sizeX) ;
                env->segment.push_back(seg) ;
                seg.pointIDA = lonInd + ((latInd)*sizeX) ;
                seg.pointIDB = lonInd-1 + ((latInd)*sizeX) ;
                env->segment.push_back(seg) ;
            }
        }
    }
    std::cout << "\nsize " << env->points.size() ;
}

void mainGame(){
    GAME game ;
    initializeGame(&game) ;
    Graphics3D graph ;

    int timerStart, timer2, timerEnd ;

    int message = winMessage(&game,&graph.m_mark.origin) ;


    // liage du moteur graphique au jeu
    /// le moteur graphique est modifié avec game
    game.viewer = &graph.camera ;
    game.viewer = &graph.camera ;

    POINT3D org ;
    org.x = org.y = org.z = 0 ;

    createSphere(&graph,org,25,1,1) ;

    graph.camera.direction.angleZ = 90 ;
    graph.m_mark.distance = 16 ;
    graph.displaySegment = false ;
    graph.displaySurfaces = false ;
    graph.displayPoint = true ;
    graph.displayMark = true ;

    while(message != EXIT){

        graph.refresh() ;
        mise_a_jour() ;

        message = winMessage(&game,&graph.m_mark.origin) ;

        switch(message){
        case EXIT :
            return ;
            break ;
        case PAUSE :
            return ;
            if(pauseScreen(&game,&graph) == EXIT)
                return ;

            break ;

        case 'W' :
            graph.m_mark.distance ++ ;
            break ;
        case 'V' :
            if(graph.m_mark.distance>2)
                graph.m_mark.distance -- ;
            break ;
        }
    }
    std::cout << time(NULL) << '\n' ;
}

void initializeGame(GAME *game){
    char mapName[] = "ressources/map/001.map" ;

    loadChunk(&game->terrain[0][0], mapName) ;


}

int pauseScreen(GAME *game, Graphics3D *env){
    int message ;
    message = winMessage(game,&((*env).m_mark.origin)) ;
    while(message != EXIT){
        drawPauseScreen(game,env) ;

        if(message == PAUSE)
            return RIEN ;

        message = winMessage(game,&((*env).m_mark.origin)) ;
    }
    return EXIT ;
}
