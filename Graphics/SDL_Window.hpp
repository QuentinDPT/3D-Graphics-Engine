#ifndef SDL_WINDOW_HPP
#define SDL_WINDOW_HPP

#include "Graphics.hpp"

#include <thread>

#define MSG

#define WIN_SHOW SDL_WINDOW_SHOWN

#define NB_MAX_SON 15

#define DEFAULT_BG_COLOR (SDL_COLOR){255,255,255}

#include <string>

class SDL_Window
{
    public:
        SDL_Window() ;
        SDL_Window(std::string name, SDL_UPOINT position, SDL_USIZE winSize, SDL_COLOR bgColor) ;
        SDL_Window(std::string name, SDL_USIZE winSize, SDL_COLOR bgColor) ;

        virtual ~SDL_Window() ;

        void refresh() ;

    protected:
        void draw() ;

        SDL_Window   *window ;
        SDL_Renderer *renderer ;


    private:
        void _refresh() ;

        std::string m_name ;

        SDL_UPOINT m_position ;
        SDL_USIZE  m_size ;

        SDL_COLOR m_bgColor ;




        // refresh thread
        std::thread m_refreshTh ;
};

#endif // SDL_WINDOW_HPP
