cmake_minimum_required(VERSION 3.16)
project(game-template)

set(CMAKE_C_VERSION 99)
add_compile_options(-Wall -Werror)
find_package(OpenGL REQUIRED)

add_subdirectory(glfw-3.4)

add_executable(game
    src/main.c
)
target_include_directories(game PRIVATE 
    include
    ${OPENGL_INCLUDE_DIRS}
    #glfw-3.4/deps
)
target_link_libraries(game PRIVATE
    glfw
    ${OPENGL_LIBRARIES}
)
