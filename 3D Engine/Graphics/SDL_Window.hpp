#ifndef SDL_WINDOW_HPP
#define SDL_WINDOW_HPP


#define WIN_SHOW          SDL_WINDOW_SHOWN
#define NB_MAX_SON        15
#define DEFAULT_BG_COLOR (SDL_COLOR){0,0,0}

#define DEFAULT_FPS       30


#include "Graphics.hpp"

#include <thread>
#include <string>
#include <vector>

class SDL_Window
{
    public:
        SDL_Window() ;
        SDL_Window(std::string name, SDL_UPOINT position, SDL_USIZE winSize, SDL_COLOR bgColor) ;
        SDL_Window(std::string name, SDL_USIZE winSize, SDL_COLOR bgColor) ;

        virtual ~SDL_Window() ;

        void refresh() ;

        void setDrawFct(void (*fct)(SDL_Renderer*)){
            m_drawFunction = fct ;
        }

        void draw() ;

        #ifdef RENDERER_HPP
        void addRenderer(Renderer renderer) ;
        #endif // RENDERER_HPP
    protected:

        SDL_Window   *m_window ;
        SDL_Renderer *m_renderer ;

        SDL_Event    *m_event ;


    private:
        void _refreshEvents() ;
        void _refreshDraw() ;

        std::string m_name ;

        SDL_UPOINT m_position ;
        SDL_USIZE  m_size ;

        SDL_COLOR m_bgColor ;

        void (*m_drawFunction)(SDL_Renderer*) ;




        // refresh thread
        std::thread m_refreshDispTh ;
        bool m_stopDispTh ;
        unsigned int m_FPS ;
};

#endif // SDL_WINDOW_HPP
