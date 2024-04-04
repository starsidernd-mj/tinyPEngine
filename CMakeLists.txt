cmake_minimum_required(VERSION 3.0)
project(tinyPEngine)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add GLFW library
find_package(glfw3 REQUIRED)

# Add GLEW library
find_package(GLEW REQUIRED)

# Add GLUT library
find_package(GLUT REQUIRED)

# Add source files
set(SOURCES
    src/Node.cpp
    src/Timer.cpp
    src/RenderBase.cpp
    src/Renderer.cpp
    src/main.cpp
    # Add more source files here if needed
)

# Set compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Include source headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link directories
link_directories(${OPENGL_LIBRARY_DIRS})

# Add executable target
add_executable(tinyPEngine ${SOURCES})

# Link libraries
target_link_libraries(tinyPEngine glfw ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES})
