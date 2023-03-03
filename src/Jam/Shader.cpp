#include <Jam/Shader.h>
using namespace std;
Jam::Shader* _selected_shader;
Jam::Shader* Jam::get_selected_shader(){return _selected_shader;};

using namespace Jam;
using namespace Jam::Math;

void compile_shader_errors(GLuint shader, string shader_name)
{
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        GLint error_mensage_len = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &error_mensage_len);

        string error_mensage;
        error_mensage.resize(error_mensage_len);

        glGetShaderInfoLog(shader, error_mensage_len, NULL, &error_mensage[0]);
        cout << "error in: " << shader_name << endl << error_mensage << endl;

        //glDeleteShader(shader);
    }
}

Shader::Shader(string vertex_shader_file, string fragment_shader_file)
{
    string vertex_shader_file_code = get_file_contents(vertex_shader_file);
    string fragment_shader_file_code = get_file_contents(fragment_shader_file);

    const char* vertex_shader_file_source = vertex_shader_file_code.c_str();
    const char* fragment_shader_file_source = fragment_shader_file_code.c_str();

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_file_source, NULL);
    glCompileShader(vertex_shader);
    compile_shader_errors(vertex_shader, vertex_shader_file);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_file_source, NULL);
    glCompileShader(fragment_shader);
    compile_shader_errors(fragment_shader, fragment_shader_file);

    ID = glCreateProgram();
    glAttachShader(ID, vertex_shader);
    glAttachShader(ID, fragment_shader);
    glLinkProgram(ID);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

void Shader::use()
{
    glUseProgram(ID);
    _selected_shader = this;
}

GLuint Shader::get_uniform_localization(std::string uniform)
{
    return glGetUniformLocation(ID, uniform.c_str());
}

void Shader::send(string uniform, int x){glUniform1i(get_uniform_localization(uniform), x);}
void Shader::send(string uniform, int x, int y){glUniform2i(get_uniform_localization(uniform), x, y);}
void Shader::send(string uniform, int x, int y, int z){glUniform3i(get_uniform_localization(uniform), x, y, z);}
void Shader::send(string uniform, int x, int y, int z, int w){glUniform4i(get_uniform_localization(uniform), x, y, z, w);}

void Shader::send(string uniform, float x){glUniform1f(get_uniform_localization(uniform), x);}
void Shader::send(string uniform, float x, float y){glUniform2f(get_uniform_localization(uniform), x, y);}
void Shader::send(string uniform, float x, float y, float z){glUniform3f(get_uniform_localization(uniform), x, y, z);}
void Shader::send(string uniform, float x, float y, float z, float w){glUniform4f(get_uniform_localization(uniform), x, y, z, w);}

void Shader::send(string uniform, vec2 value){glUniform2f(get_uniform_localization(uniform), value.x, value.y);}
void Shader::send(string uniform, vec3 value){glUniform3f(get_uniform_localization(uniform), value.x, value.y, value.z);}
void Shader::send(string uniform, vec4 value){glUniform4f(get_uniform_localization(uniform), value.x, value.y, value.z, value.w);}
void Shader::send(string uniform, mat4 value){glUniformMatrix4fv(get_uniform_localization(uniform), 1, GL_TRUE, value.v16);}