#include <stdio.h>
#include <stdlib.h>
#include "GLFW/glfw3.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        // Bail
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int WIDTH, HEIGHT;
float RATIO;
void size_change_callback(GLFWwindow* window, int width, int height)
{
    WIDTH = width;
    HEIGHT = height;
    RATIO = WIDTH / (float) HEIGHT;
    glViewport(0, 0, WIDTH, HEIGHT);
    printf("Window size: (%d, %d)\n", WIDTH, HEIGHT);
    double time_since_init = glfwGetTime();
    printf("Time since initialization: %lf sec.\n", time_since_init);
}

int main()
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // TODO: For some reason enabling either of these 2 lines breaks it.
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Some callbacks
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, size_change_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    double time_since_init = glfwGetTime();
    printf("Time since initialization: %lf sec.\n", time_since_init);

    // Set swap interval to 1 to match swap buffers monitor refresh rate
    glfwSwapInterval(1);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
