#include "OpenGLRenderer.h"
#include "GLFW/glfw3.h"
#include "../Renderer.h"
#include <iostream>

int OpenGLRenderer::Init()
{
  if (!glfwInit())
    return 1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Create a windowed mode window and its OpenGL context */
  Renderer::Window_s = glfwCreateWindow(1280, 720, "SK Engine - OpenGL", NULL, NULL);
  if (Renderer::Window_s == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }


  glfwMakeContextCurrent(Renderer::Window_s);

  return 0;
}

void OpenGLRenderer::Clear()
{
}

void OpenGLRenderer::Shutdown()
{
}
