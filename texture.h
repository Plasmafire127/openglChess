#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "stb_image.h"

class Texture2D
{
    public:
    //ID
    GLuint ID;
    //dimensions
    GLuint Width, Height;

    GLuint Internal_Format; // format of texture object
    GLuint Image_Format; // format of loaded image
    
    //texture config
    GLuint Wrap_S; //wrapping mode on S axis
    GLuint Wrap_T; //wrapping mode on T axis
    GLuint Filter_Min; //filtering mode if texture pixels < screen pixels
    GLuint Filter_Max; //filtering mode if texture pixels > screen pixls

    //constructor
    Texture2D();
    //generate texture from image data
    void Generate(GLuint width, GLuint height, unsigned char* data);
    //bind texture as the active GL_TEXTURE_2D object
    void Bind() const;

    //activate texture fn?
};

#endif