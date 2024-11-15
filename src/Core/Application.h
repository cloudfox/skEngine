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

  private:
    void LoadConfig();
    CmdLineArgs CmdLineArgs_;
    
    double time;
    double Timestep_ = 0.02;
    int frameCap_ = 255;
    std::chrono::steady_clock::time_point currentTime_;
    double accumulator;
    
    unsigned int OldFrame_ = 0;
    unsigned int CurrentFrame_ = 1;
    unsigned int SimFrame_ = 2;

    std::vector<std::thread> threads_;
    //std::counting_semaphore<1> ThreadInits_;
    
    bool InitDone = false;

    void FixedUpdate();
    void Update(double dt);


    void SimulationThread();
    void SimulationSync();

    void RenderThread();
    bool RenderSync();
  };


}//end engine namespace
