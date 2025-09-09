# GLLearn - OpenGL Learning Project

A C++ OpenGL learning project that demonstrates basic OpenGL concepts including texture loading, shader management, and 3D transformations.

## Features

- **Modern OpenGL**: Uses OpenGL 3.3 Core Profile
- **Texture Loading**: Loads and displays multiple textures using stb_image
- **Shader Management**: Clean Shader class for managing vertex and fragment shaders
- **Matrix Transformations**: Uses GLM for 3D matrix operations (translation, rotation)
- **Dual Texture Blending**: Demonstrates texture mixing in fragment shader
- **Dynamic Uniforms**: Time-based color changes and transformations

## Dependencies

- **OpenGL 3.3+**: Core graphics API
- **GLFW3**: Window and input management  
- **GLAD**: OpenGL function loader
- **GLM**: Mathematics library for graphics
- **stb_image**: Image loading library

## Building

### Prerequisites (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev mesa-common-dev libglfw3-dev libglm-dev cmake build-essential
```

### Build Steps
```bash
mkdir build
cd build
cmake ..
make
```

## Running

From the build directory:
```bash
./MyOpenGLApp
```

**Controls:**
- ESC: Exit the application

## Project Structure

```
GLLearn/
├── src/
│   ├── main.cpp        # Main application entry point
│   ├── shader.cpp      # Shader class implementation
│   ├── GLFun.cpp       # OpenGL utility functions
│   └── cppFun.cpp      # File reading utilities
├── include/
│   ├── shader.h        # Shader class header
│   ├── GLFun.h         # OpenGL function declarations
│   ├── cppFun.h        # File utility headers
│   └── stb_image.h     # Image loading library
├── resources/
│   ├── shaders/        # GLSL shader files
│   │   ├── VertexShader.glsl
│   │   └── FragmentShader.glsl
│   └── textures/       # Texture image files
│       ├── container.jpg
│       ├── awesomeface.png
│       └── wall.jpg
├── glad/               # OpenGL loader
└── CMakeLists.txt      # Build configuration
```

## What it Does

The application creates a window and renders a textured quad that:
- Rotates continuously around the Z-axis
- Displays a blended texture (container + face)
- Changes color dynamically based on time
- Demonstrates proper OpenGL resource management

## Learning Topics Covered

1. **Window Creation**: GLFW setup and OpenGL context
2. **Shader Management**: Loading, compiling, and linking shaders
3. **Texture Loading**: Image loading and OpenGL texture creation
4. **Vertex Data**: Vertex arrays, buffers, and attributes
5. **Uniforms**: Passing data from CPU to GPU
6. **Matrix Math**: 3D transformations using GLM
7. **Resource Cleanup**: Proper OpenGL resource deallocation

## Recent Improvements

- Refactored shader code into reusable Shader class
- Improved code organization and readability
- Added proper error handling for shader compilation
- Enhanced uniform setting with type-safe methods
- Better resource management and cleanup

## License

This is an educational project for learning OpenGL concepts.