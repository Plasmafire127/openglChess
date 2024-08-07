#include "game.h"
#include "spriteRenderer.h"


// Game-related State data
SpriteRenderer  *Renderer;

Game::Game(unsigned int width, unsigned int height) 
    : Width(width), Height(height)
{

}

void Game::Init()
{
    //load shaders
    ResourceManager::LoadShader("/Users/jake/Desktop/opengl/shaders/sprite.vs","/Users/jake/Desktop/opengl/shaders/sprite.frag", "spriteShader");
    //configure shaders
    //projection matrix is it updated with window resize?
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("spriteShader").Use().SetInteger("image", 0);
    ResourceManager::GetShader("spriteShader").SetMatrix4("projection", projection);

    // set render-specific controls
    Shader shader = ResourceManager::GetShader("spriteShader");
    Renderer = new SpriteRenderer(shader);

    //set shader
    ResourceManager::GetShader("spriteShader").Use();

    //load textures
    ResourceManager::LoadTexture("/Users/jake/Desktop/opengl/images/wall.jpg", false, "wall");
    //set Texture
    ResourceManager::GetTexture("wall").Bind();
    
}

void Game::Render()
{
    Texture2D texture = ResourceManager::GetTexture("wall");
    Renderer->DrawSprite(texture, glm::vec2(400.0f, 300.0f),glm::vec2(100.0f, 100.0f), 0.0f);
}  