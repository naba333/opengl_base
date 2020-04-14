#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

void error_callback(int, const char *);
static void key_callback(GLFWwindow *, int, int, int, int);
void framebuffer_size_callback(GLFWwindow *, int, int);

//settings
const unsigned int SCR_WIDTH = 1600;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    GLFWwindow *window;

    if(!glfwInit())
    {
        cout << "Error initializing OprnGL" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "openglt window", NULL, NULL);
    if(!window)
    {
        cout << "Window creation error!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //register callbacks
    glfwSetErrorCallback(error_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Glad gl loader error!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //end of main
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}


void error_callback(int error, const char *description)
{
    cerr << "Error: " << description << endl;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

//window resize callback
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}
