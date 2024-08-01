#include "InputManager.h"

#include "../Renderer/Renderer.h"

std::vector<Command> InputManager::Commands_s;

std::map<unsigned short, KeyState> InputManager::KeyStates_s;
std::multimap<unsigned short, Command*> InputManager::CommandMap_s[KeyState::Size];
std::queue<KeyInfo> InputManager::InputQueue_;

void InputManager::Init()
{
  //Setting Default values in keystates map
  //---------------------------------------------------------------
  //printable keys
  for (int key = GLFW_KEY_SPACE; key < GLFW_KEY_GRAVE_ACCENT; key++)
    KeyStates_s[key] = KeyState(glfwGetKey(Renderer::Window_s, key));

  //function keys
  for (int key = GLFW_KEY_ESCAPE; key < GLFW_KEY_LAST; key++)
    KeyStates_s[key] = KeyState(glfwGetKey(Renderer::Window_s, key));

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

    //Sets key state to either up, pressed, down, released
    KeyStates_s[key] = KeyState(keyDown + (GLFWState == GLFW_PRESS) + (2 * (GLFWState == GLFW_RELEASE)));
  }

  //function keys
  for (int key = GLFW_KEY_ESCAPE; key < GLFW_KEY_LAST; key++)
  {
    const int GLFWState = glfwGetKey(Renderer::Window_s, key);
    const int keyDown = (KeyStates_s[key] == KeyState::eDown) + (KeyStates_s[key] == KeyState::ePressed);

    //Sets key state to either up, pressed, down, released
    KeyStates_s[key] = KeyState(keyDown + (GLFWState == GLFW_PRESS) + (2 * (GLFWState == GLFW_RELEASE)));
  }

  //If pressed/down/release, Run Associated Commands.
  // TODO:  move commands to queue for processing in game Update()
  for (const auto& [key, value] : KeyStates_s) {
    auto it = CommandMap_s[value].equal_range(key);
    for (auto itr = it.first; itr != it.second; ++itr)
      itr->second->perform();
  }
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

