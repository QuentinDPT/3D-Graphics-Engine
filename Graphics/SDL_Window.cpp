#include "SDL_Window.hpp"

SDL_Window::SDL_Window(){
    m_name = "simple window" ;
    m_size = {750, 500} ;

    SDL_Window(m_name,m_size, DEFAULT_BG_COLOR) ;
}

SDL_Window::SDL_Window(std::string name, SDL_UPOINT position, SDL_USIZE winSize, SDL_COLOR bgColor = DEFAULT_BG_COLOR) :
    m_name(name), m_position(position), m_size(winSize), m_bgColor(bgColor)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        return ;

    /*
    if(TTF_Init() == -1)
        return ;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
        return ;

    Mix_AllocateChannels(NB_MAX_SON);

    // Initialisation son
    Mix_Chunk* son[NB_MAX_SON];
    for(unsigned int i = 0 ; i<NB_MAX_SON ; i++){
        son[i]=NULL;
    }
    */

    window = SDL_CreateWindow(m_name.c_str(),
                              m_position.x, m_position.y,
                              m_size.length, m_size.height,
                              SDL_WINDOW_SHOWN) ;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) ;

    SDL_SetRenderDrawColor(renderer,
                           m_bgColor.r, m_bgColor.g, m_bgColor.b, 255) ;
    SDL_RenderClear(renderer) ;
    SDL_RenderPresent(renderer) ;
}

SDL_Window::SDL_Window(std::string name, SDL_USIZE winSize, SDL_COLOR bgColor = DEFAULT_BG_COLOR){
    SDL_Window(name,
               ((SDL_UPOINT){SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}),
               winSize,
               bgColor) ;
}

SDL_Window::~SDL_Window()
{
    //dtor
}


