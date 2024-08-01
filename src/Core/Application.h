#pragma once
/*!*****************************************************************************
\file     Application.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


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
    Application();
    ~Application();


    int Init(CmdLineArgs CmdArgs);
    int Shutdown();

    int Run();

  public:
    LuaCppApi LuaAPI_;

    //void LoadScene(Scene& scene);

  private:
    bool isRunning_ = false;
    void LoadConfig();
    CmdLineArgs CmdLineArgs_;
    
    double Timestep_ = 0.02;
    void FixedUpdate();
    void Update(double dt);

  };



}//end engine namespace


