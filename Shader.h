#pragma once
#ifndef __SHADER__
#define __SHADER__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm\glm\glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    Shader() {};
    //Shader(const char* vertexPath, const char* fragmentPath);
    void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr); // note: geometry source code is optional
    Shader& useProgram();
    void deleteProgram();
    void SetFloat(const char* name, float value, bool useShader = false);
    void SetInteger(const char* name, int value, bool useShader = false);
    void SetVector2f(const char* name, float x, float y, bool useShader = false);
    void SetVector2f(const char* name, const glm::vec2& value, bool useShader = false);
    void SetVector3f(const char* name, float x, float y, float z, bool useShader = false);
    void SetVector3f(const char* name, const glm::vec3& value, bool useShader = false);
    void SetVector4f(const char* name, float x, float y, float z, float w, bool useShader = false);
    void SetVector4f(const char* name, const glm::vec4& value, bool useShader = false);
    void SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false);
    void checkCompileErrors(unsigned int object, std::string type);
private:
    unsigned int _shaderProgram = 0;
};

#endif


