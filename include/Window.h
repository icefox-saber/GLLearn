#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GLFun.h"

class Window
{
private:
    GLFWwindow *window;
public:
    Window(int Major = 3,int Minor = 3, int Width = 800, int Height = 600);
    GLFWwindow * Get();
    ~Window();
};

Window::Window(int Major,int Minor,int Width,int Height)
{
        glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(Width, Height, "LearnGL", nullptr, nullptr);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

}

inline GLFWwindow *Window::Get()
{

    return window;
}

Window::~Window()
{
}
