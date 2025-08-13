#pragma once

#include <filesystem>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "cppFun.h"
class Shader
{
private:
    int ID;
public:
    Shader(std::filesystem::path VertexShaderPath,std::filesystem::path FragmentShaderPath);
    void Use();
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
    ~Shader();
};
 
Shader::Shader(std::filesystem::path VertexShaderPath,std::filesystem::path FragmentShaderPath)
{
    int success;
    int VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    auto VertexShader = ReadFile<std::string>(VertexShaderPath);
    const char *VertexShaderSource = VertexShader.data();
    glShaderSource(VertexShaderID, 1, &VertexShaderSource, nullptr);
    glCompileShader(VertexShaderID);
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(VertexShaderID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    int FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    auto FragmentShader = ReadFile<std::string>(FragmentShaderPath);
    const char *FragmentShaderSource = FragmentShader.data();
    glShaderSource(FragmentShaderID, 1, &FragmentShaderSource, nullptr);
    glCompileShader(FragmentShaderID);
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(FragmentShaderID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::Fragment::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    int PrograID = glCreateProgram();
    glAttachShader(PrograID, VertexShaderID);
    glAttachShader(PrograID, FragmentShaderID);
    glLinkProgram(PrograID);
    glGetProgramiv(PrograID, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(PrograID, 512, nullptr, infoLog);
        std::cout << "ERROR::ProgramID::Link_FAILED\n"
                  << infoLog << std::endl;
    }

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
}

inline void Shader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

inline void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

inline void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}
