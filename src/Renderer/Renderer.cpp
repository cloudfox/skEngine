/*!*****************************************************************************
\file     Renderer.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "Renderer.h"
#include <iostream>

#include "OpenGL/OpenGLRenderer.h"
//#include "Vulkan/VulkanRenderer.h"
#include "../Core/Application.h"
#include "../Entity/EntityManager.h"
#include "../Entity/components/Transform.h"
#include "../Entity/components/mesh.h"

#include "glm/gtx/scalar_multiplication.hpp"


namespace Engine{


std::unique_ptr<RendererAPI> Renderer::RendererAPI_s;
RenderApiType Renderer::API_s = RenderApiType::OpenGL;
GLFWwindow* Renderer::Window_s;

std::vector<Shader> Renderer::shaders_s;

glm::vec4 Renderer::ClearColor_s{ 0.1f, 0.1f, 0.1f, 1.0f };
double Renderer::alpha_{ 0 };



//for testing ---------------------
std::vector<int> indices;
unsigned int VBO, VAO, EBO;
float vertices[] = {
	// positions         // colors
	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};
//--------------------------------


void Renderer::Init(RenderApiType api)
{
  API_s = api;

	//selecting the graphics library to use
	//should be possible to switch while running but probably not worth the hassle
	switch (API_s)
	{
	default:
	case RenderApiType::OpenGL:  
		RendererAPI_s = std::make_unique<OpenGLRenderer>() ;
		break;
	case RenderApiType::Vulkan:  //Vulkan Render
		//RendererAPI_s = new VulkanRenderer;
		RendererAPI_s = std::make_unique<OpenGLRenderer>(); //TODO Vulkan 
		int blah = 0;
		break;
	}

	RendererAPI_s->Init();

	shaders_s.resize(1);
	shaders_s[0].load("assets/shaders/Shader.vert", "assets/shaders/Shader.frag");


	indices = {
				0, 1, 3, // first triangle
				1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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
	//glfwMakeContextCurrent(Window_s);
	glClearColor(ClearColor_s.r, ClearColor_s.g, ClearColor_s.b, ClearColor_s.a);
	//glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw()
{
	auto view = EntityManager::Registry_s.view<Transform,const Mesh>();

	for (auto [entity, transform, mesh] : view.each()) {
		glm::vec3 pos = (1 - alpha_) * transform.position[Application::CurrentFrame_]
										  + (alpha_) * transform.position[Application::SimFrame_];
		pos.x += 1;
	}

	glm::vec3 color = glm::vec3(0.5, 0.0, 0.0);
	Clear();
//	Renderer::shaders_s[0].SetVec3("aColor", color);
	Renderer::shaders_s[0].use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);


	glfwSwapBuffers(Window_s);
}


}
