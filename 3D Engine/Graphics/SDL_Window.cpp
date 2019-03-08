#include "SDL_Window.hpp"

#include <iostream>
#include <algorithm> // std::find

SDL_Window::SDL_Window() :  SDL_Window("simple window",{750, 500}, DEFAULT_BG_COLOR) {}

SDL_Window::SDL_Window(std::string name, SDL_USIZE winSize, SDL_COLOR bgColor = DEFAULT_BG_COLOR){
    SDL_Window(name,
               ((SDL_UPOINT){SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}),
               winSize,
               bgColor) ;
}

SDL_Window::SDL_Window(std::string name, SDL_UPOINT position, SDL_USIZE winSize, SDL_COLOR bgColor = DEFAULT_BG_COLOR) :
    m_name(name), m_position(position), m_size(winSize), m_bgColor(bgColor), m_FPS(DEFAULT_FPS)
{
    m_drawFunction = nullptr ;

    m_event = new SDL_Event ;

    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "probleme lors de la mise en place du thread\n\tError code :  " << SDL_GetError() ;
        return ;
    }


    /* Gestion des polices d'écritures
    if(TTF_Init() == -1)
        return ;
    //*/

    /* Gestion de l'audio
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
        return ;
    Mix_AllocateChannels(NB_MAX_SON);

    // Initialisation son
    Mix_Chunk* son[NB_MAX_SON];
    for(unsigned int i = 0 ; i<NB_MAX_SON ; i++){
        son[i]=NULL;
    }
    //*/

    // Creation de la fenetre
    m_window = SDL_CreateWindow(m_name.c_str(),
                                m_position.x, m_position.y,
                                m_size.length, m_size.height,
                                SDL_WINDOW_SHOWN) ;

    // Creation d'un rendu associé a la fenetre
    m_renderer = SDL_CreateRenderer(m_window, -1, DEFAULT_RENDERER) ;


    //* Ouverture du thread d'affichage
    m_stopDispTh = false ;
    m_refreshDispTh = std::thread(&SDL_Window::_refreshDraw,this) ;
    //*/
}

SDL_Window::~SDL_Window(){
    //* Fermeture du thread d'affichage
    m_stopDispTh = true ;
    m_refreshDispTh.join() ;
    //*/
}


void SDL_Window::refresh(){
    // Catch des events
    if(!SDL_PollEvent(m_event)){
        switch(m_event->type){
        case(SDL_QUIT) :
            break ;
        case(SDL_WINDOWEVENT) :
            break ;
        case(SDL_KEYDOWN) :
            break ;
        case(SDL_KEYUP) :
            break ;
        case(SDL_MOUSEMOTION) :
            break ;
        case(SDL_MOUSEBUTTONDOWN) :
            break ;
        case(SDL_MOUSEBUTTONUP) :
            break ;
        case(SDL_MOUSEWHEEL) :
            break ;
        case(SDL_DROPFILE) :
            break ;
        case(SDL_TOUCH_MOUSEID) :
            break ;
        default :
            std::cout << "action inconnue\n" ;
            break ;
        }
    }
}

void SDL_Window::draw(){
    // Texture de fond
    SDL_SetRenderDrawColor(m_renderer,
                           m_bgColor.r, m_bgColor.g, m_bgColor.b, 255) ;

    // Application du fond à la fenetre
    SDL_RenderClear(m_renderer) ;

    // Afficher l'environnement
    if(m_drawFunction != nullptr)
        m_drawFunction(m_renderer) ;

    // affichage du rendu
    SDL_RenderPresent(m_renderer) ;
}



// Fonction de refresh de tous les objets graphiques
void SDL_Window::_refreshDraw(){
    // Boucle de thread
    do{
        draw() ;
    }while(!m_stopDispTh) ;
}


// Fonction de refresh de tous les evenements de la fenetre
void SDL_Window::_refreshEvents(){
    // Boucle de thread
    do{
        refresh() ;
    }while(!m_stopDispTh) ;
}

