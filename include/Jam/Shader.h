#ifndef SHADER_H_
#define SHADER_H_

#include "Utils.h"

#include "Math/vec2.h"
#include "Math/vec3.h"
#include "Math/vec4.h"
#include "Math/mat4.h"

namespace Jam
{
    class Shader
    {
        public:
            Shader(std::string vertex_shader_file, std::string fragment_shader_file);
            ~Shader();

            void use(void);
            
            void send(std::string uniform, int x);
            void send(std::string uniform, int x, int y);
            void send(std::string uniform, int x, int y, int z);
            void send(std::string uniform, int x, int y, int z, int w);

            void send(std::string uniform, float x);
            void send(std::string uniform, float x, float y);
            void send(std::string uniform, float x, float y, float z);
            void send(std::string uniform, float x, float y, float z, float w);

            void send(std::string uniform, Math::vec2 value);
            void send(std::string uniform, Math::vec3 value);
            void send(std::string uniform, Math::vec4 value);
            void send(std::string uniform, Math::mat4 value);
            
        private:
            GLuint get_uniform_localization(std::string uniform);

            GLuint ID;
    };
    
    Shader* get_selected_shader();
}

#endif