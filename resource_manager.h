//a resource manager loads and handles different openGL objects
//will be utilized within game.cpp
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <glad/glad.h>

#include "texture.h"
#include "shader.h"

//static items exist independently of a ResourceManager object/instance
//note return types as well. Some return Shader Objects, some return Texture2D Objects, etc.
class ResourceManager
{
    public:
    //resource storage, think python dictionary where key = unique string name and value = Shader/Texture
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;

    //retreive a stored shader 
    static Shader GetShader(std::string name);

    //retreive a stored texture 
    static Texture2D GetTexture(std::string name);

    //load and generate a shader program via loading shader source files
    static Shader LoadShader(const char  *vFile, const char *fFile, std::string name);

    //load and generate a texture
    static Texture2D LoadTexture(const char *file, bool alpha, std::string name);

    private:
        //private constructor since we don't want any instances of our Resource Manager
        ResourceManager(){}

        //loads and generates a shader from file, used by LoadShader fn
        static Shader loadShaderFromFile(const char *vFile, const char *fFile);

        //loads and generates a texture from file, used by LoadTexture fn
        static Texture2D loadTextureFromFile(const char *file, bool alpha);
};



#endif