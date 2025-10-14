#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

#include "vgl.h"
#include "LoadShaders.h"

enum VAO_IDs
{
  Triangles,
  NumVAOs
};

enum Buffer_IDs
{
  ArrayBuffer,
  NumBuffers
};

enum Attrib_IDs
{
  vPosition = 0
};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;

int init(void)
{
  static const GLfloat vertices[NumVertices][2]{
      {-0.90, -0.90},
      {0.85, -0.90},
      {-0.90, 0.85},
      {0.90, -0.85},
      {0.90, 0.90},
      {-0.85, 0.90}};

  glCreateVertexArrays(NumVAOs, VAOs);

  glCreateBuffers(NumBuffers, Buffers);
  glNamedBufferStorage(Buffers[NumBuffers], sizeof(vertices), vertices, 0);

  ShaderInfo shaders[] = {
      {GL_VERTEX_SHADER, "triangles.vert"},
      {GL_FRAGMENT_SHADER, "triangles.frag"},
      {GL_NONE, NULL}};

  GLuint program = LoadShaders(shaders);
  glUseProgram(program);
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  glEnableVertexAttribArray(vPosition);



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