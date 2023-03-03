#ifndef UTILS_H_
#define UTILS_H_

#ifdef ANDROID
    #include <SDL.h>
    #include <SDL_opengles2.h>
    #ifndef GLES2
        #define GLES2
    #endif
#else
    #include <SDL2/SDL.h>
    #include "../glad/glad.h"
    #ifndef GL33
        #define GL33
    #endif
#endif

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "../stb_image.h"

namespace Jam
{
    std::string get_file_contents(std::string path);
}

#endif