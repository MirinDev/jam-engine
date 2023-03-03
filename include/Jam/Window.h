#ifndef WINDOW_H_
#define WINDOW_H_

#include "Utils.h"

namespace Jam
{
    class Window
    {
        public:
            Window(std::string title, int width, int height);
            Window(std::string title, int width, int height, bool resizable);
            Window(std::string title, int width, int height, bool resizable, bool fullscreen);
            ~Window();

            void render(void);

            void get_size(int* x, int* y);
            int get_width(void);
            int get_height(void);
            bool is_fullscreen(void);
            bool is_resizable(void);

            void set_fullscreen(bool value);
            void set_resizable(bool value);
            void set_size(int width, int height);
        
        private:
            SDL_Window* window;
            SDL_GLContext gl;

            bool resizable = false;
            bool fullscreen = false;
    };
}

#endif