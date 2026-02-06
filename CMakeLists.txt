cmake_minimum_required(VERSION 3.16)
project(gyoza)

include(FetchContent)

FetchContent_Declare(UnderCore
GIT_REPOSITORY git@github.com:Papyrus219/UnderCore.git
GIT_TAG main
GIT_SHALLOW ON)

set(Render_src render/src/render_manager.cpp)

set(Physic_src physic/src/physic_component.cpp)

set(Resources_src resources/src/resource_manager.cpp)

add_executable(${PROJECT_NAME}
    ${Render_src}
    ${Physic_src}
    ${Resources_src}
    src/main.cpp)

FetchContent_MakeAvailable(UnderCore)

target_link_libraries(${PROJECT_NAME} PRIVATE
    UnderCore
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

