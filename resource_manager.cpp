#include "resource_manager.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include "shader.h"
#include "stb_image.h"



// Instantiate static variables (belong to class)
//creates map with key string, value Shader/Texture2D pair and assigns the map to the Textures or Shaders static variable of the ResourceManager class
std::map<std::string, Shader>       ResourceManager::Shaders;
std::map<std::string, Texture2D>    ResourceManager::Textures;


//load a shader from source code and assign it a unique name
Shader ResourceManager::LoadShader(const char *vFile, const char *fFile, std::string name)
{
    //assigns map to new shader
    Shaders[name] = loadShaderFromFile(vFile, fFile);
    //should use getShader if previously loaded right?
    return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    //should use getTexture if previously loaded right?
    return Textures[name];
}


Shader ResourceManager::loadShaderFromFile(const char *vFile, const char *fFile)
{
    //initiate strings that will hold the vertex/fragment source code retrieved from the filepath
    std::string vertexCode;
    std::string fragmentCode;
    try
    {
        {
            //open files
            std::ifstream vertexShaderFile(vFile);
            std::ifstream fragmentShaderFile(fFile);
            //read files buffer contents into streams
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();
            //close file handlers
            vertexShaderFile.close();
            fragmentShaderFile.close();
            //convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
    }
    catch(const std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" <<std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    //now create a new shader object from our derived source code, and return the shader object for use
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode);
    return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    //create a pointer to a texture object
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    else
    {
        texture.Internal_Format = GL_RGB;
        texture.Image_Format = GL_RGB;
    }
    texture.Wrap_S=GL_REPEAT;
    texture.Wrap_T=GL_REPEAT;
    texture.Filter_Min=GL_LINEAR_MIPMAP_LINEAR;
    texture.Filter_Max=GL_LINEAR;
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    if(!data)
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    // now generate texture
    texture.Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}

Shader ResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

Texture2D ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}