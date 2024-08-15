#pragma once
/*!*****************************************************************************
\file     Scene.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


#include "../Entity/EntityManager.h"




class Scene 
{
public:
  virtual ~Scene() = default;

  void LoadScene();
  void SaveScene();

  //void LoadSubScene();  //Loads another scenes entities inside thise scene

private:
  std::string SceneName_;
  EntityManager EntityManager_;
};
