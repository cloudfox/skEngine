/*!*****************************************************************************
\file     OpenGLRenderer.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


#include "OpenGLRenderer.h"

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "../Renderer.h"

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
  glfwSetFramebufferSizeCallback(Renderer::Window_s, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }


  return 0;
}

void OpenGLRenderer::Clear()
{
}

void OpenGLRenderer::Shutdown()
{
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  // make sure the viewport matches the new window dimensions; note that width and 
  // height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}