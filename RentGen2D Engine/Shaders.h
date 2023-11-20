#pragma once
#include "KHR/khrplatform.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class VertexShader
{
public:
    const char* shaderCode = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    unsigned int shader;

    void CreateShader();
};
class FragmentShader
{
public:
    const char* shaderCode =
        "#version 330 core"
        "out vec4 FragColor;"
        "void main()"
        "{"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
        "}";
    unsigned int shader;
    void CreateShader();
};

class ShaderProgramm
{
public:
    unsigned int shaderProgramm;

    void CreateProgram(VertexShader vertexShader, FragmentShader fragmentShader);
};
class Texture
{
public:
    float texCoords[6] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f };
    int width, height, nrChannels;
    unsigned int texture;

    void TextureInitialization();
    void LoadTexture(const char* textureName);
};
