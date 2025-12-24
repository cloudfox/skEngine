/*!*****************************************************************************
\file     main.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/
#include <iostream>
#include "Core/Application.h"

/*  General Engine Flow
  App Construction    //kept minimal
  App Init            //2nd phase bulk of startup is here
    Systems Init
      >Load config
      >Render Init
      >Input Init
  App Run - Main Loop
    Input
    Game Logic
    AI
    Physics
    Audio
    Video
  App Shutdown
    Systems Shutdown


*/


int main(int argc, char** argv)
{
  //Engine::Application* App = new Engine::Application();
  std::unique_ptr<Engine::Application> App = std::make_unique<Engine::Application>();

  try {
    App->Init({ argc, argv });
    App->Run();
    App->Shutdown();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
