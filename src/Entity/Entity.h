#pragma once

#include "entt/entt.hpp"


class Entity
{
public:
  Entity() = default;
  Entity(entt::entity id);
  Entity(const Entity& other) = default;


  operator bool() const { return EnttHandle != entt::null; }
  operator entt::entity() const { return EnttHandle; }

  bool operator==(const Entity& other) const  {    return EnttHandle == other.EnttHandle;  }
  bool operator!=(const Entity& other) const  {    return !(*this == other);  }

  template<typename T, typename... Args>
  T& AddComponent(Args&&... args)
  {
    return EntityManager::AddComponent<T>(*this, T);
  }


  //{
  //  T& component = m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
  //  m_Scene->OnComponentAdded<T>(*this, component);
  //  return component;
  //}


private:
  entt::entity EnttHandle = entt::null;

  friend class Scene;
  friend class EntityManager;
};

