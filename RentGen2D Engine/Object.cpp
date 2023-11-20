#include "Object.h"

void Triangle::CreateBuffer()
{
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_DYNAMIC_DRAW);
}
void Triangle::LinkVerticles()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void Triangle::VertexPositionsT()
{
    verticles[0] = (posX - scaleX) * 0.2f;   verticles[1] = (posY - scaleY) * 0.2f;   verticles[2] = 0.0f;
    verticles[3] = (posX + scaleX) * 0.2f;   verticles[4] = (posY - scaleY) * 0.2f;   verticles[5] = 0.0f;
    verticles[6] = (posX + scaleX) * 0.2f;   verticles[7] = (posY + scaleY) * 0.2f;   verticles[8] = 0.0f;
}
void Square::CreateBuffer()
{
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void Square::VertexPositionsS()
{
    verticles[0] = (posX - scaleX) * 0.2f;   verticles[1] = (posY - scaleY) * 0.2f;   verticles[2] = 0.0f;
    verticles[3] = (posX + scaleX) * 0.2f;   verticles[4] = (posY - scaleY) * 0.2f;   verticles[5] = 0.0f;
    verticles[6] = (posX + scaleX) * 0.2f;   verticles[7] = (posY + scaleY) * 0.2f;   verticles[8] = 0.0f;
    verticles[9] = (posX - scaleX) * 0.2f;   verticles[10] = (posY + scaleY) * 0.2f;   verticles[11] = 0.0f;
}
int ObjsOnScene::triangsCount = 0;
int ObjsOnScene::squaresCount = 0;

Triangle ObjsOnScene::triangsOnScene[99];
Square ObjsOnScene::squaresOnScene[99];