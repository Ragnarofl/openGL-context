#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <iostream>

struct spritePoint {
    float pointX;
    float pointY;
    float textureX;
    float textureY;
};

// Texture2D is able to store and configure a texture in OpenGL.
// It also hosts utility functions for easy management.
class Texture2D
{
public:
    // holds the ID of the texture object, used for all texture operations to reference to this particlar texture
    unsigned int ID;
    // texture image dimensions
    unsigned int Width, Height; // width and height of loaded image in pixels
    // texture offset/imageCount if it's a spritesheet
    unsigned int offset = 0;
    unsigned int spriteCount = 0;
    unsigned int currentSprite = 0;
    // texture vertices in case of a spritesheet
    spritePoint* vertices;
    // texture Format
    unsigned int Internal_Format; // format of texture object
    unsigned int Image_Format; // format of loaded image
    // texture configuration
    unsigned int Wrap_S; // wrapping mode on S axis
    unsigned int Wrap_T; // wrapping mode on T axis
    unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
    unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels
    // constructor (sets default texture modes)
    Texture2D();
    // generates texture from image data
    void Generate(unsigned int width, unsigned int height, unsigned char* data, unsigned int offset = 0, unsigned int spriteCount = 0);
    // generate a set of vertices in case of a spritesheet
    void GenVertices();
    // binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;
};

#endif


