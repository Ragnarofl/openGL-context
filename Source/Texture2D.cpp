#include "Texture2D.h"

Texture2D::Texture2D()
    : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
    glGenTextures(1, &this->ID);

    spritePoint vertices[] = {
        // pos      // tex
        {0.0f, 0.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 1.0f, 1.0f},
    };
    this->vertices = vertices;
}

void Texture2D::Generate(unsigned int width, unsigned int height, unsigned char* data, unsigned int offset, unsigned int spriteCount)
{
    this->Width = width;
    this->Height = height;

    this->offset = offset;
    this->spriteCount = spriteCount;
    if (offset != 0)
        this->GenVertices();
    // create Texture
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
    // set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::GenVertices()
{
    this->vertices = (spritePoint*)malloc(sizeof(spritePoint) * 4 * this->spriteCount);
    float imgSize = 1.0f / (this->Width / this->offset);

    //std::cout << "imgSize: " << imgSize << std::endl;

    for (int i = 0; i < this->spriteCount; i++) {
        vertices[0 + 4 * i] = { (float)(i + 0) * imgSize, 0.0f, (float)(i + 0) * imgSize, 0.0f };
        vertices[1 + 4 * i] = { (float)(i + 1) * imgSize, 0.0f, (float)(i + 1) * imgSize, 0.0f };
        vertices[2 + 4 * i] = { (float)(i + 0) * imgSize, 1.0f, (float)(i + 0) * imgSize, 1.0f };
        vertices[3 + 4 * i] = { (float)(i + 1) * imgSize, 1.0f, (float)(i + 1) * imgSize, 1.0f };
    }
    //this->vertices = vertices;

    /*for (int i = 0; i < 4 * this->spriteCount; i++) {
        std::cout << this->vertices[i].pointX << ", ";
        std::cout << this->vertices[i].pointY << ", ";
        std::cout << this->vertices[i].textureX << ", ";
        std::cout << this->vertices[i].textureY << "\n";
    }*/
}

void Texture2D::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
