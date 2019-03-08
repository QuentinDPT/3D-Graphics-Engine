#include "controllerIO.hpp"
#include "Structures.hpp"
#include "easysdl.hpp"

#include <windows.h>
#include <fstream>

#include <iostream>

using namespace std ;

bool rightClick ;
bool leftClick ;
POINT2D backupMouse ;



int winMessage(GAME *game, POINT2D *focus){
    int message ;
    char key ;

    recupere_evenement_continu(&message) ;

    switch(message){
    case EXIT :
        return EXIT ;
        break ;
    case SOURIS_MOUVEMENT :
    case SOURIS_BOUTON_DROITE_ENFONCE :
    case SOURIS_BOUTON_DROITE_RELACHE :
    case SOURIS_BOUTON_GAUCHE_ENFONCE :
    case SOURIS_BOUTON_GAUCHE_RELACHE :
        if(!game->pause)
            _mouseEvent(game,message,focus) ;
        break ;
    case TOUCHE_ENFONCEE :
        key = touche() ;
        switch(key){
        case ESCAPE :
            return PAUSE ;
            break ;
        default :
            return key ;
        }
        if(!game->pause)
            _keyEvent(game,key) ;
        break ;
    case TOUCHE_RELACHEE :
        break ;
    }
    return RIEN ;
}

void _mouseEvent(GAME *game, int message, POINT2D *focus){
    switch(message){
    case SOURIS_MOUVEMENT :
        if(rightClick){
            POINT point ;
            GetCursorPos(&point) ;
            game->viewer->direction.angleX -= point.x-backupMouse.x ;
            game->viewer->direction.angleZ -= point.y-backupMouse.y ;
            setWinCursor(backupMouse) ;
        }else if(leftClick){
            focus->x = souris_x() ;
            focus->y = souris_y() ;
        }

        break ;
    case SOURIS_BOUTON_DROITE_ENFONCE :
        rightClick = true ;
        POINT point ;
        GetCursorPos(&point) ;
        backupMouse.x = point.x ;
        backupMouse.y = point.y ;
        displayCursor(false) ;
        break ;
    case SOURIS_BOUTON_DROITE_RELACHE :
        displayCursor(true) ;
        rightClick = false ;
        break ;
    case SOURIS_BOUTON_GAUCHE_ENFONCE :
        leftClick = true ;
        break ;
    case SOURIS_BOUTON_GAUCHE_RELACHE :
        leftClick = false ;
        break ;
    }
}

void _keyEvent(GAME *game, char key){

    switch(key){
    case CONTROL_UP :
        break ;
    case CONTROL_DOWN :
        break ;
    case CONTROL_RIGHT :
        break ;
    case CONTROL_LEFT :
        break ;
    }

}

void loadChunk(CHUNK *chunk, char mapName[]){
    ifstream directory(mapName) ;
}

void setWinCursor(POINT2D point){
    setWinCursor(point.x,point.y) ;
}

void setWinCursor(int x, int y){

    SetCursorPos(x,y) ;
}

void displayCursor(bool visible){

    CONSOLE_CURSOR_INFO lpCursor ;
    lpCursor.bVisible = visible ;
    lpCursor.dwSize = 0 ;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&lpCursor) ;

}

