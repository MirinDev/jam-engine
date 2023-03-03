#include <Jam/Window.h>
using namespace std;
using namespace Jam;

Window::Window(string title, int width, int height)
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    gl = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl);
}

Window::Window(string title, int width, int height, bool resizable)
{
    int flags = SDL_WINDOW_OPENGL;
    if (resizable) flags |= SDL_WINDOW_RESIZABLE;
    this->resizable = resizable;

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    gl = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl);
}

Window::Window(string title, int width, int height, bool resizable, bool fullscreen)
{
    int flags = SDL_WINDOW_OPENGL;
    if (resizable) flags |= SDL_WINDOW_RESIZABLE;
    if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    this->resizable = resizable;
    this->fullscreen = fullscreen;
    
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    gl = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl);
}

Window::~Window()
{
    SDL_GL_DeleteContext(gl);
    SDL_DestroyWindow(window);
}

void Window::render()
{
    SDL_GL_SwapWindow(window);
}

void Window::get_size(int* x, int* y)
{
    SDL_GetWindowSize(window, x, y);
}

int Window::get_width()
{
    int w;
    SDL_GetWindowSize(window, &w, NULL);
    return w;
}

int Window::get_height()
{
    int h;
    SDL_GetWindowSize(window, NULL, &h);
    return h;
}

bool Window::is_fullscreen()
{
    return fullscreen;
}

bool Window::is_resizable()
{
    return resizable;
}

void Window::set_fullscreen(bool value)
{
    SDL_SetWindowFullscreen(window, value ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    fullscreen = value;
}

void Window::set_resizable(bool value)
{
    SDL_SetWindowResizable(window, value ? SDL_TRUE : SDL_FALSE);
    resizable = value;
}

void Window::set_size(int width, int height)
{
    SDL_SetWindowSize(window, width, height);
}