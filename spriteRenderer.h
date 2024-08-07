#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class SpriteRenderer
{

    glm::vec2 position; //translate
    glm::vec2 size; //scale
    float rotate; //rotate
    
    public:
        //constructor, input shader to use for transformations
        SpriteRenderer(Shader &shader);

        //draw sprite
        void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size, float rotate);

    private:
        Shader shader; 
        GLuint quadVAO;

        void initRenderData();
};

#endif