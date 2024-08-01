#include "LuaCppApi.h"

#include <iostream>
#include <sol/assert.hpp>

LuaCppApi::LuaCppApi()
{
}

LuaCppApi::~LuaCppApi()
{
}

int LuaCppApi::Init()
{
  Lua_.open_libraries(sol::lib::base, sol::lib::io, sol::lib::math, sol::lib::table);

  return 0;
}

int LuaCppApi::LoadFile(std::string file)
{
  try
  {
    Lua_.safe_script_file(file);
    std::cout << "[CPP S1] Lua File read OK!\n";
  }
  catch (const sol::error& e)
  {
    std::cout << std::string(e.what()) << "\n";
    return 1;
  }

  return 0;
}

//lua read simple variable
//Lua_.["a"].get_or(0)
//Lua_.["a"].get_or<std::string>("0")

// explicit type
//auto a_double = lua["a"].get<double>()

//existance check
//sol::optional<double> optional_double = lua["a"]
