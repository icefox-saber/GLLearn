#pragma once

#include "cppFun.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <filesystem>
class Shader {
  private:
    int ID;

  public:
    Shader(std::filesystem::path VertexShaderPath, std::filesystem::path FragmentShaderPath);
    void Use();
    int GetID();
    void Set(const std::string &name, bool value) const;
    void Set(const std::string &name, int value) const;
    void Set(const std::string &name, float value) const;
    ~Shader();
};
