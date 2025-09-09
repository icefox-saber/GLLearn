#pragma once

#include "GLFun.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
  private:
    GLFWwindow *window;

  public:
    Window(int Major = 3, int Minor = 3, int Width = 800, int Height = 600);
    GLFWwindow *Get();
    ~Window();
};
