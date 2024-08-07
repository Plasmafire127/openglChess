#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "game.h"

//declare functions
void processInput(GLFWwindow *window);
//callback functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);  

// The Width of the screen
unsigned int SCREEN_WIDTH = 800;
// The height of the screen
unsigned int SCREEN_HEIGHT = 600;

int main()
{
    //initialize glfw functions and configure window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Chess!", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    


    //set Viewport size
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //reset size when window changes ("call this fn when framebuffersize changes")
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    //enable alpha transparency/blendering
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //game stuff
    Game Chess(SCREEN_WIDTH,SCREEN_HEIGHT);
    //initialize, loading shaders, textures, etc.
    Chess.Init();

    //deltaTime
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    //render loop
    while(!glfwWindowShouldClose(window))
    {
        //calculate deltaTime
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //checks for inputs
        processInput(window);

        //background color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //draw
        Chess.Render();

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}








//change window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //retina displays wack
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}  

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}