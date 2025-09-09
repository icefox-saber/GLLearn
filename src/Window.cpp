#include "Window.h"
#include <cassert>

Window::Window(int Major, int Minor, int Width, int Height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(Width, Height, "LearnGL", nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
}

GLFWwindow *Window::Get() {
    return window;
}

Window::~Window() {}
