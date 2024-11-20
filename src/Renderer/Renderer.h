#pragma once
/*!*****************************************************************************
\file    Renderer.h
\author  Steven Kugies
\par     www.skugies.com
\par     skugies.dev@gmail
*******************************************************************************/

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RenderConfig.h"
#include "RendererAPI.h"


#include <memory>
#include <cstdint>
#include <glm/vec4.hpp>
#include <vector>

#include "Shader.h"

namespace Engine {


  //Acts as an abstraction layer to whatever graphics library is set at startup
  class Renderer
  {
  public:
    Renderer() = default;
    ~Renderer() = default;

    static void Init(RenderApiType api);
    static void Shutdown();

    static void OnWindowResize(uint32_t width, uint32_t height);

    //static void SetViewport( );
    //static void SetClearColor(const glm::vec4& color)
    static void Clear();
    static void Draw();
    //static void DrawLines();

    static void SetAlpha(double a) { alpha_ = a; }

  private:
    static RenderApiType API_s;  //enum for what graphics api are we using
    static std::unique_ptr<RendererAPI> RendererAPI_s; //the actual graphics api(opengl/vulkan)

    static glm::vec4 ClearColor_s;


    static double alpha_;//percent towards next fixed update

  public:
    static GLFWwindow* Window_s;

    static std::vector<Shader> shaders_s;
  };

}