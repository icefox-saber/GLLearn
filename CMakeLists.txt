cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#  将 glad 添加为子目录。
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glm glm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw glfw)

# 移动资源文件夹Resources到项目根目录
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#find_package(OpenGL REQUIRED)

include_directories(`
    #${OPENGL_INCLUDE_DIR}
    #${glfw3_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include # 添加项目头文件路径
)

file(GLOB SRC_FILES src/*.cpp)
add_executable(MyOpenGLApp ${SRC_FILES})

target_link_libraries(MyOpenGLApp
    #${OPENGL_LIBRARIES}
    glfw
    glad # 链接 glad 库
    glm
)