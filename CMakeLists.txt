cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#  将 glad 添加为子目录。
add_subdirectory(external/glad glad)

# 移动资源文件夹Resources到项目根目录
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/shaders")
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${glfw3_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include # 添加 glad 头文件路径
)

add_executable(MyOpenGLApp src/main.cpp)

target_link_libraries(MyOpenGLApp
    ${OPENGL_LIBRARIES}
    glfw
    glad # 链接 glad 库
)