#pragma once
#include "../Entity/EntityManager.h"




class Scene 
{
public:
  virtual ~Scene() = default;

  void LoadScene();
  void SaveScene();

private:
  std::string SceneName_;
  EntityManager EntityManager_;
};
