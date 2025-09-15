#pragma once

#include "cppFun.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <filesystem>
class Shader {
  private:
    int ID;

public:
    Shader(std::filesystem::path VertexShaderPath, std::filesystem::path FragmentShaderPath);
    void use();
    int GetID();
    void Set(const std::string &name, bool value) const;
    void Set(const std::string &name, int value) const;
    void Set(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec3(const std::string &name, const glm::vec3 &vec) const;
    ~Shader();
};
