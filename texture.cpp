#include "texture.h"
#include <iostream>

//constructor
Texture2D::Texture2D(){}

//Generate texture
void Texture2D::Generate(GLuint width, GLuint height, unsigned char* data)
{
    Width = width;
    Height = height;
    glGenTextures(1, &this->ID);  
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, width, height, 0, Image_Format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    // set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);
}

//Bind texture
void Texture2D::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);  
}