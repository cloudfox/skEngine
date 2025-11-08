/*!*****************************************************************************
\file     InputManager.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "InputManager.h"

#include "../Renderer/Renderer.h"

namespace Engine {

std::vector<Command> InputManager::Commands_s;

std::map<unsigned short, KeyState> InputManager::KeyStates_s;
std::map<unsigned short, KeyState> InputManager::GameKeyStates_s;
std::multimap<unsigned short, Command*> InputManager::CommandMap_s[4];
rigtorp::SPSCQueue<KeyInfo> InputManager::InputQueue_s(100);

void InputManager::Init()
{
  //Setting Default values in keystates map
  //---------------------------------------------------------------
  //printable keys
  for (int key = GLFW_KEY_SPACE; key < GLFW_KEY_GRAVE_ACCENT; key++)
  {
    KeyStates_s[key] = KeyState(glfwGetKey(Renderer::Window_s, key));
    GameKeyStates_s[key] = KeyStates_s[key];
  }

  //function keys
  for (int key = GLFW_KEY_ESCAPE; key < GLFW_KEY_LAST; key++)
  {
    KeyStates_s[key] = KeyState(glfwGetKey(Renderer::Window_s, key));
    GameKeyStates_s[key] = KeyStates_s[key];
  }
}

//Records the current GLFW key states
void InputManager::HandleInput()
{
  glfwPollEvents();

  //glfw key codes match with ascii table, does not use lowercase
  //GLFW_KEY_A = 65

  //GLFW_Release = 0
  //GLFW_PRESS = 1
  //GLFW_Repeat = 2

  //printable keys
  for (int key = GLFW_KEY_SPACE; key < GLFW_KEY_GRAVE_ACCENT; key++)
  {
    const int GLFWState = glfwGetKey(Renderer::Window_s, key);
    const int keyDown = (KeyStates_s[key] == KeyState::eDown) + (KeyStates_s[key] == KeyState::ePressed);

    //determine new key state to either up, pressed, down, released
    KeyState state = KeyState(keyDown + (GLFWState == GLFW_PRESS) + (2 * (GLFWState == GLFW_RELEASE && (KeyStates_s[key] != KeyState::eUp && KeyStates_s[key] != KeyState::eReleased))));

    //if keystate has changed add relevant commands to queue
    (state == KeyStates_s[key] || AddToQueue(KeyInfo(key, state)) );
  }

  //function keys
  for (int key = GLFW_KEY_ESCAPE; key < GLFW_KEY_LAST; key++)
  {
    const int GLFWState = glfwGetKey(Renderer::Window_s, key);
    const int keyDown = (KeyStates_s[key] == KeyState::eDown) + (KeyStates_s[key] == KeyState::ePressed);

    //determine new key state to either up, pressed, down, released
    KeyState state = KeyState(keyDown + (GLFWState == GLFW_PRESS) + (2 * (GLFWState == GLFW_RELEASE && GLFWState != KeyState::eUp))); 

    //if keystate has changed add relevant commands to queue
    (state == KeyStates_s[key] || AddToQueue(KeyInfo(key, state)));
  }
}

bool InputManager::AddToQueue(KeyInfo k)
{
  KeyStates_s[k.key] = k.state;
  InputQueue_s.push(k); 
  return true;
}

void InputManager::SyncInput()
{
  KeyInfo* k = InputQueue_s.front();
  while (k != nullptr)
  {
    if (GameKeyStates_s[k->key] != k->state)
    {
      //If pressed/down/release, Run Associated Commands.
      auto it = CommandMap_s[k->state].equal_range(GameKeyStates_s[k->key]);
      for (auto itr = it.first; itr != it.second; ++itr)
        itr->second->perform();
    }

    GameKeyStates_s[k->key] = k->state;

    InputQueue_s.pop();
    k = InputQueue_s.front();
  }
}

//Mostly for testing
KeyState InputManager::KeyStatus(unsigned short key)
{
  return GameKeyStates_s.at(key);
}


void InputManager::LoadCommandBindings()
{
  //load from file

  //if file doesn't exist or is corrupted
  //1. clear anything loaded so far
  //2. Load Defaults
  LoadDefaultCommandBindings();
}

void InputManager::LoadDefaultCommandBindings()
{
}

//Called if user changes default bindings
void InputManager::SaveBindings()
{
}



}
