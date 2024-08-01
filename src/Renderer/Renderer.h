#pragma once

#include "RenderConfig.h"
#include "RendererAPI.h"
#include "GLFW/glfw3.h"

#include <memory>
#include <cstdint>
#include <glm/vec4.hpp>

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


private:
  static RenderApiType API_s;  //enum for what graphics api are we using
  static std::unique_ptr<RendererAPI> RendererAPI_s; //the actual graphics api(opengl/vulkan)
  
  static glm::vec4 ClearColor_s;

public:
  static GLFWwindow* Window_s;
  
};

