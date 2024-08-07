#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "resource_manager.h"

class Game
{

    public:
        // game state
        unsigned int Width, Height;
        // constructor/destructor
        Game(unsigned int width, unsigned int height);

        void Init();
        void ProcessInput();
        void Render();
};

#endif