#pragma once
/*!*****************************************************************************
\file     Mesh.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include <vector>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

struct Mesh
{
  Mesh() = default;
  Mesh(const Mesh& other) {
    verts = other.verts;
    vNormals = other.vNormals;
    vertexIndices = other.vertexIndices;
    fNormals = other.fNormals;
  }
  ~Mesh() = default;

  std::vector<glm::vec4> verts;
  std::vector<unsigned int> vertexIndices;
  std::vector< glm::vec4> vNormals;
  std::vector< glm::vec4> fNormals;
};
