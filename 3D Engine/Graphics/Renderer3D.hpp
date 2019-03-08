#ifndef RENDERER3D_HPP
#define RENDERER3D_HPP

#ifndef RENDERER_HPP
#define RENDERER_HPP

class Renderer
{
    public:
        Renderer(SDL_Window *win) ;
        virtual ~Renderer();

    protected:
        SDL_Event  *m_event ;
        SDL_Window *m_win ;

        void _refresh() ;
    private:
};
#endif // RENDERER_HPP


class Renderer3D : public Renderer
{
    public:
        Renderer3D();
        virtual ~Renderer3D();

    protected:

    private:
};

#endif // RENDERER3D_HPP
