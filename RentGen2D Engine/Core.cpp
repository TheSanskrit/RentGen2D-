#include "Object.h"
#include "Graphics.h"
#include "Input.h"
#include <iostream>

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    Triangle triangle1;
    triangle1.posX = 1.0f;
    triangle1.posY = 0.0f;
    triangle1.scaleX = 1.0f;
    triangle1.scaleY = 1.0f;

    ObjsOnScene::triangsCount = 1;
    ObjsOnScene::triangsOnScene[0] = triangle1;

    Square square1;
    //square1.posX = 4.0f;
    //square1.posY = 4.0f;
    //square1.scaleX = 1.0f;
    //square1.scaleY = 1.0f;

    ObjsOnScene::squaresCount = 1;
    ObjsOnScene::squaresOnScene[0] = square1;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1440, 960, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.75f, 0.72f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Drawer::DrawObjects();

        //CursorInput::GetCursorPosition();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}