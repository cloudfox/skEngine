/*!*****************************************************************************
\file     Application.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "Application.h"
#include <semaphore>

#include "../Renderer/Renderer.h"
#include "InputManager.h"

namespace Engine
{
  std::counting_semaphore<1> TimeSync(1);
  std::counting_semaphore<1> SimRenderSync(1);

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

  int Application::Init(CmdLineArgs CmdArgs)
  {
    CmdLineArgs_ = CmdArgs;
    LoadConfig();

    Renderer::Init(RenderApiType::OpenGL);
    InputManager::Init();
    LuaAPI_.Init();

    return 0;
  }

  void Application::LoadConfig()
  {
  }

  int Application::Shutdown()
  {
    Renderer::Shutdown();
    return 0;
  }

  int Application::Run()
  {
    //double time = 0;  //How long the engine has been running

    //auto currentTime = std::chrono::steady_clock::now();
    //double accumulator = Timestep_;   //tracks time since last FixedUpdate

    ////TODO How would I multithread this?
    //while (!glfwWindowShouldClose(Renderer::Window_s))
    //{
    //  accumulator += GetFixedDeltaTime(currentTime);

    //  //Input
    //  InputManager::HandleInput();

    //  //consume accumulated time
    //  while (accumulator >= Timestep_)
    //  {
    //    FixedUpdate();

    //    accumulator -= Timestep_;
    //    time += Timestep_;
    //  }
    //  //mainly video and audio
    //  Update(accumulator/Timestep_);
    //}
    

    //Startup Threads
    //------------
    //Input Thread
    //Audio Thread
    //Simulation Thread
    //Render Thread
    
    threads_.push_back(std::thread(&Application::SimulationThread, this));
    threads_.push_back(std::thread(&Application::RenderThread, this));

    while (!threads_.empty())
      threads_.front().join();

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

  void Application::SimulationThread()
  {  

    time = 0;  //How long the engine has been running

    TimeSync.acquire();
    currentTime_ = std::chrono::steady_clock::now();
    TimeSync.release();

    accumulator = Timestep_;   //tracks time since last FixedUpdate

    //Main Loop
    //---------
    while (!glfwWindowShouldClose(Renderer::Window_s))
    {
      TimeSync.acquire();
      accumulator += GetFixedDeltaTime(currentTime_);
      TimeSync.release();

      //consume accumulated time
      while (accumulator >= Timestep_)
      {
        FixedUpdate();

        accumulator -= Timestep_;
        time += Timestep_;
      }
      SimulationSync();
    }
  }

  void Application::SimulationSync()
  {
    //Signal Render it is waiting for sync
    SimRenderSync.acquire();
    
    OldFrame_ = CurrentFrame_;
    CurrentFrame_ = SimFrame_;
    SimFrame_ = (SimFrame_ + 1) % 2;


    //wait for RenderSync
    SimRenderSync.release();
    std::this_thread::sleep_for(std::chrono::microseconds(1));
  }

  void Application::RenderThread()
  {
    //Sets this thread as the one GLFW runs and updates from
    glfwMakeContextCurrent(Renderer::Window_s);


    while (!glfwWindowShouldClose(Renderer::Window_s))
    {
      //Get how long the current Simulation frame has been running
      //as a percentage to the next frame
      TimeSync.acquire();
      auto newTime = std::chrono::steady_clock::now();
      auto duration = std::chrono::duration<double>(newTime - currentTime_);
      Renderer::SetAlpha(duration.count() / Timestep_);
      TimeSync.release();

      //TODO Framerate Cap


      //Actual rendering starts here
      Renderer::Draw();

      //Check if Render needs to sync with Simulation thread
      RenderSync();
    }
  }

  // Checks if it needs to wait for Simulation Thread to switch to new targets
  //
  // return: true when sync thread has finished a loop, otherwise false
  bool Application::RenderSync()
  {
    //release to check if simulation thread is done
    SimRenderSync.release();

    std::this_thread::sleep_for(std::chrono::microseconds(1));

    if (SimRenderSync.try_acquire())
    {
      return false; 
    }
    else {
      //wait for sim thread to be done
      SimRenderSync.acquire();
      return true; //return true to reset accumulation
    }
  }


}//end engine namespace
