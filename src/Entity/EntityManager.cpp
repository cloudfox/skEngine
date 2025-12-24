/*!*****************************************************************************
\file     EntityManager.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "EntityManager.h"

#include "Entity.h"
#include "components/ComponentsList.h"

entt::registry EntityManager::Registry_s;
std::vector<entt::entity> EntityManager::entities_s;
Mesh* sphere;

void EntityManager::Init()
{
  entities_s.push_back(Registry_s.create());
  Registry_s.emplace<Transform>(entities_s.front(), Transform());
  Registry_s.emplace<Mesh>(entities_s.front(), Mesh());

  sphere = CreateSphereMesh(5);
  Entity sphereEntity = CreateEntity();


  //Registry_s.emplace<Mesh>(entities_s.front(), sphere);
  Mesh& component = Registry_s.emplace_or_replace<Mesh>(sphereEntity, *sphere);
}

void EntityManager::Shutdown()
{
  delete sphere;

}

Entity EntityManager::CreateEntity()
{
  Entity entity = { Registry_s.create() };


  return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
  Registry_s.destroy(entity);
}


//template<typename T, typename... Args>
//void EntityManager::AddComponent(T& component, Entity entity)
//{
//  T& component = Registry_.emplace_or_replace<T>(entity.EnttHandle, std::forward<Args>(args)...);
//  return component;
//}
