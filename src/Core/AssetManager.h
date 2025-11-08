/*!*****************************************************************************
\file     AssetManager.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#pragma once

#include <string>
#include <map>

struct Mesh;

enum AssetType { mesh, texture, normalMap };

struct AssetInfo {
  std::string filename;
  AssetType type;
};

using AssetMap = std::map<AssetInfo, uint64_t>;

class AssetManager
{
  AssetManager();

  void LoadMesh(unsigned int ID); //load by ID from asset map
  void LoadMesh(std::string file); //load by file name
  


  //ID Map - id to asset file name
  //Loaded Assets map - id to the loaded asset
  //asset use count - id to how many times asset has been used

  //pre load assets
  //unload assets

private:
  void SaveAssetDB();
  void LoadAssetDB();
  bool scanForNewAssets();



private:
  const std::string ASSET_FOLDER = "assets";
  const std::string ASSET_DB_FILE = "asset_manifest.txt";
  AssetMap AssetMap_;
  uint64_t nextID = 0;
  
  //Assets
  //std::vector<unsigned int, Mesh> MeshMap_;
  //std::vector<uint64_t, Texture> TextureMap_;

};

