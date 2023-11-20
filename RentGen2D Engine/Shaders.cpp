#include "Shaders.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void VertexShader::CreateShader()
{
    shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);
}
void FragmentShader::CreateShader()
{
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);
}
void ShaderProgramm::CreateProgram(VertexShader vertexShader, FragmentShader fragmentShader)
{
    shaderProgramm = glCreateProgram();
    glAttachShader(shaderProgramm, vertexShader.shader);
    glAttachShader(shaderProgramm, fragmentShader.shader);
    glLinkProgram(shaderProgramm);
}
void Texture::TextureInitialization()
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
void Texture::LoadTexture(const char* textureName)
{
    unsigned char* data = stbi_load(textureName, &width, &height, &nrChannels, 4);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}