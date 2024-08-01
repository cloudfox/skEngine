#pragma once

#pragma warning(push, 0)
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#pragma comment(lib, "lua54.lib")
#pragma warning(pop)


class LuaCppApi
{
public:
  LuaCppApi();
  ~LuaCppApi();

  int Init();

  int LoadFile(std::string file);

private:
  sol::state Lua_;


};

