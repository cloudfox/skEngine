#pragma once
/*!*****************************************************************************
\file     EntityManager.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "entt/entt.hpp"
//#include "Entity.h"

class Entity;
struct mesh;

class EntityManager
{
public:
  static void Init();
  static void Shutdown();

  static Entity CreateEntity();
  static void DestroyEntity(Entity entity);

  //template<typename T>
  //static void AddComponent(T& component, Entity entity)
  //{
  //  T& component = Registry_.emplace_or_replace<T>(entity.EnttHandle, std::forward<Args>(args)...);
  //  return component;
  //}

  

  static entt::registry Registry_s;

  static std::vector<entt::entity> entities_s;



};

