cmake_minimum_required(VERSION 3.16)
project(opengl-template)

set(CMAKE_C_VERSION 99)
add_compile_options(-fsanitize=address -fno-omit-frame-pointer -Wall -Werror)
add_link_options(-fsanitize=address)
find_package(OpenGL REQUIRED)

add_subdirectory(glfw-3.4)

add_executable(template
    src/main.c
)
target_include_directories(template PRIVATE 
    include
    ${OPENGL_INCLUDE_DIRS}
    #glfw-3.4/deps
)
target_link_libraries(template PRIVATE
    glfw
    ${OPENGL_LIBRARIES}
)
