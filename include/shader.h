#pragma once

#include <filesystem>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
    unsigned int ID;
public:
    Shader(std::filesystem::path VertexShaderPath, std::filesystem::path FragmentShaderPath);
    void Use();
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
    void SetMat4(const std::string &name, const glm::mat4 &mat) const;
    void SetVec4(const std::string &name, const glm::vec4 &value) const;
    unsigned int GetID() const { return ID; }
    ~Shader();
};