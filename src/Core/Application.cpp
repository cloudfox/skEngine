#include "Application.h"
#include <chrono>

#include "../Renderer/Renderer.h"
#include "InputManager.h"

namespace Engine
{

  struct AppConfig {
    int screenWidth;
    int screenHeight;

  };


  //given a point in time return how much time has passed since then
  inline float GetFixedDeltaTime(std::chrono::steady_clock::time_point& current)
  {
    auto newTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration<float>(newTime - current);
    float frameTime = duration.count();
    current = newTime;

    //lag spike mitigation
    if (frameTime > 0.25f)
      frameTime = 0.25f;

    return frameTime;
  }


  Application::Application() {
  }

  Application::~Application() {

  }

  int Application::Init(CmdLineArgs CmdArgs)
  {
    CmdLineArgs_ = CmdArgs;
    LoadConfig();

    Renderer::Init(RenderApiType::OpenGL);
    InputManager::Init();
    LuaAPI_.Init();

    isRunning_ = true;
    return 0;
  }

  int Application::Shutdown()
  {
    Renderer::Shutdown();
    return 0;
  }

  int Application::Run()
  {
    double time = 0;  //How long the engine has been running

    auto currentTime = std::chrono::steady_clock::now();
    double accumulator = Timestep_;   //tracks time since last FixedUpdate

    //TODO How would I multithread this?
    while (isRunning_ && !glfwWindowShouldClose(Renderer::Window_s))
    {
      accumulator += GetFixedDeltaTime(currentTime);

      //Input
      InputManager::HandleInput();

      //consume accumulated time
      while (accumulator >= Timestep_)
      {
        FixedUpdate();

        accumulator -= Timestep_;
        time += Timestep_;
      }
      //mainly video and audio
      Update(accumulator/Timestep_);
    }

    return 0;
  }



  void Application::FixedUpdate()
  {
    //game logic
    // -AI
    //physics

  }

  void Application::Update(double dt)
  {
    //Audio

    //Video
    Renderer::Draw();


  }

  void Application::LoadConfig()
  {
  }









}//end engine namespace


