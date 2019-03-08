#define SDL_MAIN_HANDLED

#include <iostream>
#include "Renderer3D.hpp"
#include "SDL_Window.hpp"


using namespace std;

void ddd(SDL_Renderer *render){
    SDL_Rect rectangle={100,100,100,250};
    SDL_SetRenderDrawColor(render,255,0,0,255);
    SDL_RenderFillRect(render,&rectangle);
}

int main()
{/*
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "probleme lors de la mise en place du thread\n\tError code :  " << SDL_GetError() ;
        return 1 ;
    }*/

    bool quit = false  ;

    SDL_Window win ;
    win.setDrawFct(ddd) ;

    while(!quit){
        //win.refresh() ;
        win.draw() ;
        SDL_Delay(100) ;
    }




    return 0;
}
