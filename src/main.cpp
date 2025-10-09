#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

int init(void) {

}



int main(int argc, char **argv)
{
  glfwInit();
  GLFWwindow *window = glfwCreateWindow(640, 500, "OpenGL", NULL, NULL);
  gl3wInit();

  while (!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  glfwDestroyWindow(window);
  glfwTerminate();
}