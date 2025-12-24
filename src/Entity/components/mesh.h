#pragma once
/*!*****************************************************************************
\file     Mesh.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include <vector>
#include <string>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glad/glad.h>




struct Vertex
{
  Vertex(glm::vec3 pos, glm::vec3 nrm, glm::vec3 tex, glm::vec2 uv) : pos(pos), nrm(nrm), tex(tex), uv(uv) {}
  Vertex() : pos(glm::vec3()), nrm(glm::vec3()), tex(glm::vec3()), uv(glm::vec2()) {}

  glm::vec3 pos, nrm, tex;
  glm::vec2 uv;
};


struct VertexLayout
{
  int location;
  int size;
  int type;
  bool normalized;
  int offset;
};

const VertexLayout vLayout[] =
{
    { 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, pos) },
    { 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, nrm) },
    { 4, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, uv) }
};


struct Mesh
{
  Mesh() {
    verts.clear();
    indices.clear();
  };

  Mesh(const Mesh& other) {
    verts.clear();
    indices.clear();
    verts = other.verts;
    indices = other.indices;
  }

  ~Mesh() = default;


  std::vector<Vertex> verts;
  std::vector<int> indices;

  GLuint VAO{};
  GLuint VBO{};
  GLuint IBO{};
};



bool LoadMesh(std::string filename, Mesh& mesh);

Mesh* CreateSphereMesh(int size);