#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "GLFun.h"
#include "cppFun.h"
#include "shader.h"
#include "Window.h"
#include <iostream>
#include <array>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



int main()
{
    Window wd;
    GLFWwindow *window = wd.Get();

    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("./resources/textures/container.jpg", &width, &height, &nrChannels, 0);
    if (!data)
    {
        std::cout << "Loading image failed" << std::endl;
        return -1;
    }

   

    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    data = stbi_load("./resources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
    if (!data)
    {
        std::cout << "Loading image failed" << std::endl;
        return -1;
    }
    unsigned int texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    Shader sd("./resources/shaders/VertexShader.glsl","./resources/shaders/FragmentShader.glsl");

    std::array<float, 32> vertices = {
        -0.5f,
        -0.5f,
        0.f,
        1.0f,
        0.f,
        0.f,
        0.f,
        0.f,

        0.5f,
        -0.5f,
        0.f,
        0.0f,
        1.f,
        0.f,
        1.f,
        0.f,

        -0.5f,
        0.5f,
        0.f,
        1.0f,
        0.f,
        0.f,
        0.f,
        1.f,

        0.5f,
        0.5f,
        0.f,
        0.0f,
        1.f,
        0.f,
        1.f,
        1.f,
    };

    std::array<unsigned int, 6> indices = {0, 1, 2, 1, 2, 3};

    unsigned int VBO, VAO, VEO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VEO);
    glGenBuffers(1, &VBO);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VEO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    glBindVertexArray(VAO);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(sd.GetID());
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, 0.5f, 0.0f));
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        unsigned int transformLoc = glGetUniformLocation(sd.GetID(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniform1i(glGetUniformLocation(sd.GetID(), "Texture1"), 0);
        glUniform1i(glGetUniformLocation(sd.GetID(), "Texture2"), 1);
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(sd.GetID(), "outColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glBindVertexArray(VAO);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}