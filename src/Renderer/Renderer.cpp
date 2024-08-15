/*!*****************************************************************************
\file     Renderer.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "Renderer.h"
#include "GLFW/glfw3.h"
#include <iostream>

#include "OpenGL/OpenGLRenderer.h"
//#include "Vulkan/VulkanRenderer.h"
glm::vec4 Renderer::ClearColor_s{ 0.50f, 0.5f, 0.5f, 1.0f };
double Renderer::alpha_{ 0 };

std::unique_ptr<RendererAPI> Renderer::RendererAPI_s;
RenderApiType Renderer::API_s = RenderApiType::OpenGL;
GLFWwindow* Renderer::Window_s;

void Renderer::Init(RenderApiType api)
{
  API_s = api;

	//selecting the graphics library to use
	//should be possible to switch while running but probably not worth the hassle
	switch (API_s)
	{
	case RenderApiType::OpenGL:  
		RendererAPI_s = std::make_unique<OpenGLRenderer>() ;
	case RenderApiType::Vulkan:
		//RendererAPI_s = new VulkanRenderer;
		break;
	}

	RendererAPI_s->Init();

}

void Renderer::Shutdown()
{
	glfwSetWindowShouldClose(Window_s, true);

	RendererAPI_s->Shutdown();

	glfwDestroyWindow(Window_s);
	glfwTerminate();
}

void Renderer::OnWindowResize(uint32_t width, uint32_t height)
{
}

void Renderer::Clear()
{
	glfwMakeContextCurrent(Window_s);
	glClearColor(ClearColor_s.r, ClearColor_s.g, ClearColor_s.b, ClearColor_s.a);
	//glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw()
{
	Clear();

	glfwSwapBuffers(Window_s);
}
