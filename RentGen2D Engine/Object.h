#pragma once
#include "Shaders.h"

class Object
{
public:
    float posX;
    float posY;

    float scaleX;
    float scaleY;
};

class Triangle:public Object
{
public:
    float verticles[9] = { -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f,  0.5f, 0.0f };

    VertexShader vShad;
    FragmentShader fShad;
    ShaderProgramm sProg;

    unsigned int VBO;
    unsigned int VAO;

    void CreateBuffer();
    void LinkVerticles();
    void VertexPositionsT();

};
class Square:public Object
{
public:
    float verticles[12] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
    };
    unsigned int indices[6] = {
        0, 1, 3,
        1, 2, 3
    };

    VertexShader vShad;
    FragmentShader fShad;
    ShaderProgramm sProg;

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    
    void CreateBuffer();
    void VertexPositionsS();
};

class ObjsOnScene
{
public:
    static int triangsCount;
    static int squaresCount;

    static Triangle triangsOnScene[99];
    static Square squaresOnScene[99];
};
