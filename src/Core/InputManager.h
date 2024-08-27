#pragma once
/*!*****************************************************************************
\file     InputManager.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


#include <map>
#include <queue>
#include "../Utilities/SPSCQueue.h"

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
  static void SyncInput();

private:
  static std::vector<Command> Commands_s;

  static std::map<unsigned short, KeyState> KeyStates_s;
  static std::map<unsigned short, KeyState> GameKeyStates_s;
  static std::multimap<unsigned short, Command*> CommandMap_s[KeyState::Size];
  
  //static std::queue<KeyInfo> InputQueue_s;
  static rigtorp::SPSCQueue<KeyInfo> InputQueue_s;

private:
  static bool AddToQueue(KeyInfo k);

  static void LoadCommandBindings();
  static void LoadDefaultCommandBindings();
  static void SaveBindings();
  

};