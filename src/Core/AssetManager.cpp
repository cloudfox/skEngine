/*!*****************************************************************************
\file     AssetManager.cpp
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "AssetManager.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../Entity/components/mesh.h"
#include <iostream>


AssetManager::AssetManager()
{
  //TODO load asset map json file
  //while (not end of file)
  //{
  //  int id = 0;
  //  std::string fname = "";

  //  AssetMap_[id] = (fname);
  //}

}

void AssetManager::LoadMesh(unsigned int ID)
{
  /*
  AssetMap_[ID] = Mesh();
  Mesh& mesh = AssetMap_[ID];

  std::ifstream stream;
  stream.open(AssetFileMap_[ID]);

  glm::vec4 accumulator(0);


  while (!stream.eof())
  {


  }*/


}

void AssetManager::LoadMesh(std::string file)
{

}

void AssetManager::SaveAssetDB()
{

}

void AssetManager::LoadAssetDB()
{
  
}

bool AssetManager::scanForNewAssets()
{
  return false;
}


