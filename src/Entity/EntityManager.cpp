/*!*****************************************************************************
\file     EntityManager.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "EntityManager.h"

#include "Entity.h"
#include "components/ComponentsList.h"


entt::registry EntityManager::Registry_;

Entity EntityManager::CreateEntity()
{
  Entity entity = { Registry_.create() };


  return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
  Registry_.destroy(entity);
}


//template<typename T, typename... Args>
//void EntityManager::AddComponent(T& component, Entity entity)
//{
//  T& component = Registry_.emplace_or_replace<T>(entity.EnttHandle, std::forward<Args>(args)...);
//  return component;
//}
