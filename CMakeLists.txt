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

set(Render_src render/src/render_manager.cpp
render/src/render_component.cpp
render/src/texture.cpp
render/src/vertex.cpp
render/src/lib/camera.cpp
render/src/lib/fly_camera.cpp
render/src/lib/fps_camera.cpp
render/src/lib/shader.cpp
render/src/lib/stb_image.cpp
render/src/render_components_constructors/cuber_render_component.cpp)

set(Physic_src physic/src/physic_component.cpp)

set(Resources_src resources/src/resource_manager.cpp)

add_executable(${PROJECT_NAME}
    ${Render_src}
    ${Physic_src}
    ${Resources_src}
    src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glm::glm
    glad
    glfw
    OpenGL::GL
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

