#pragma once
#include "entt/entt.hpp"
//#include "Entity.h"

class Entity;

class EntityManager
{
public:
  static Entity CreateEntity();
  static void DestroyEntity(Entity entity);

  //template<typename T>
  //static void AddComponent(T& component, Entity entity)
  //{
  //  T& component = Registry_.emplace_or_replace<T>(entity.EnttHandle, std::forward<Args>(args)...);
  //  return component;
  //}


private:
  static entt::registry Registry_;
};

