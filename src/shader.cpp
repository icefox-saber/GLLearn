#include "shader.h"
#include "cppFun.h"
#include <iostream>

Shader::Shader(std::filesystem::path VertexShaderPath, std::filesystem::path FragmentShaderPath)
{
    int success;
    
    // Vertex Shader
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

    // Fragment Shader
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
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Shader Program
    ID = glCreateProgram();
    glAttachShader(ID, VertexShaderID);
    glAttachShader(ID, FragmentShaderID);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // Clean up shaders
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetVec4(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}