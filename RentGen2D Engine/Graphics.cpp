#include "Graphics.h"

void Drawer::DrawObjects()
{
	for (int i = 0; i < ObjsOnScene::triangsCount; i++)
	{
		Drawer::DrawTriangle(ObjsOnScene::triangsOnScene[i]);
	}
	for (int i = 0; i < ObjsOnScene::squaresCount; i++)
	{
		Drawer::DrawSquare(ObjsOnScene::squaresOnScene[i]);
	}
}
void Drawer::DrawSquare(Square square)
{
	square.VertexPositionsS();
	square.CreateBuffer();
	square.vShad.CreateShader();
	square.fShad.CreateShader();
	square.sProg.CreateProgram(square.vShad, square.fShad);

	glBindVertexArray(square.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, square.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(square.verticles), square.verticles, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glUseProgram(square.sProg.shaderProgramm);
	glBindVertexArray(square.VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
void Drawer::DrawTriangle(Triangle triangle)
{
	triangle.VertexPositionsT();
	triangle.CreateBuffer();
	triangle.LinkVerticles();
	triangle.vShad.CreateShader();
	triangle.fShad.CreateShader();
	triangle.sProg.CreateProgram(triangle.vShad, triangle.fShad);

	glBindVertexArray(triangle.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle.verticles), triangle.verticles, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glUseProgram(triangle.sProg.shaderProgramm);
	glBindVertexArray(triangle.VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDeleteShader(triangle.vShad.shader);
	glDeleteShader(triangle.fShad.shader);
}