cmake_minimum_required(VERSION 3.16)
project(gyoza)

set(CMAKE_C_STANDARD 11)

add_library(glad STATIC
    glad/src/glad.c
)

target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/glad/include
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/lib/shader.cpp
    src/lib/camera.cpp
    src/lib/fly_camera.cpp
    src/lib/fps_camera.cpp
    src/stb_image.cpp
)

target_link_libraries(${PROJECT_NAME}
    glm::glm
    glad
    glfw
    OpenGL::GL
)

