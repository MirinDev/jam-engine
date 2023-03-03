#include <Jam/Jam.h>

void Jam::open()
{
    #ifdef GL33
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_VIDEO_OPENGL);
        
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    #else 
        #ifdef GLES2
            SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_VIDEO_OPENGL_ES2);

            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        #endif
    #endif
}

void Jam::close()
{
    SDL_Quit();
}

void Jam::loadGL()
{
    #ifdef GL33
        gladLoadGL();
    #endif

    glEnable(GL_DEPTH_TEST);
}

void Jam::set_viewport(int x, int y, int w, int h){glViewport(x, y, w, h);}
void Jam::set_clear_color(float r, float g, float b, float a){glClearColor(r, g, b, a);}
void Jam::clear(void){glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);};

bool _is_running = true;
SDL_Event _events;

bool Jam::is_running(void){return _is_running;}

void Jam::update_events(void)
{
    while(SDL_PollEvent(&_events))
    {
        switch (_events.type)
        {
        case SDL_QUIT:
            _is_running = false;
            break;
        }
    }
}
