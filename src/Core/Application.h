#pragma once
/*!*****************************************************************************
\file     Application.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include <chrono>
#include <thread>
#include <semaphore>
#include <condition_variable>
#include <mutex>

#include "../Entity/EntityManager.h"
#include "LuaCppApi.h"

namespace Engine
{
  //class Scene;
  //class SceneManager;
  //class AssetManager;

  struct CmdLineArgs
  {
    int count = 0;
    char** args = nullptr;

    const char* operator[](int index) const
    {
      return args[index];
    }
  };


  struct AppConfig {
    int screenWidth{ 1280 };
    int screenHeight{ 720 };
    bool limitFrameRate{ false };
    unsigned int frameRateCap{ 60 };
  };

  class  Application
  {
  public:
    Application() = default;
    ~Application() = default;

    int Init(CmdLineArgs CmdArgs);
    int Shutdown();

    int Run();

  public:
    LuaCppApi LuaAPI_;
    

    //void LoadScene(Scene& scene);

    static unsigned int OldFrame_;
    static unsigned int CurrentFrame_;
    static unsigned int SimFrame_;

  private:
    void LoadConfig();
    CmdLineArgs CmdLineArgs_;
    AppConfig appConfig_;
    
    double time;
    double Timestep_ = 0.02;
    std::chrono::steady_clock::time_point currentTime_;
    double accumulator;
    


    std::vector<std::thread> threads_;
    //std::counting_semaphore<1> ThreadInits_;
    
    bool InitDone = false;

    void FixedUpdate();
    void Update(double dt);

    void waitForInit();
    void SimulationThread();
    void SimulationSync();

    void RenderThread();
    bool RenderSync();
  };


}//end engine namespace
