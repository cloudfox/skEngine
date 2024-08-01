#pragma once
 
#include <map>
#include <queue>


class Command {
  //action name
  //type: pressed/held/released
  //float amount;

  //Command Name
  //
  //Action* action;
public:
  void perform() {};
  void undo() {};
};

enum KeyState {
  eUp = 0,
  ePressed = 1,
  eDown = 2,
  eReleased = 3,
  Size = 4
};

struct KeyInfo {
  KeyInfo(int k, KeyState s) : state(s), key(k) {};
  int key : 16;
  KeyState state : 16;
};


class InputManager 
{
public:
  static void Init();
  static void HandleInput();

private:
  static std::vector<Command> Commands_s;

  static std::map<unsigned short, KeyState> KeyStates_s;
  static std::multimap<unsigned short, Command*> CommandMap_s[KeyState::Size];

  static std::queue<KeyInfo> InputQueue_;
  // static std::queue<unsigned int, KeyState> CommandQueue;

private:
  static void LoadCommandBindings();
  static void LoadDefaultCommandBindings();
  static void SaveBindings();
  

};