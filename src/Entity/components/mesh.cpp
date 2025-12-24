#include "mesh.h"

#include <sstream>
#include <fstream>



bool LoadMesh(std::string filename, Mesh& mesh)
{
 



  return 0;
}


Mesh* CreateSphereMesh(int size)
{
  Mesh* newmesh = new Mesh;
  Mesh& mesh = *newmesh;

  const int M = size * 2;
  const int totalVerts = M * (size - 1) + 2;
  mesh.verts.resize(totalVerts);

  //verts
  for (int i = 1; i < size; ++i)
  {
    float theta = 3.14159f * i / size;
    for (int j = 0; j < M; ++j) {
      int index = M * (i - 1) + j;
      float phi = 2 * 3.14159f * j / M;
      mesh.verts[index].nrm.x = sin(theta) * cos(phi);
      mesh.verts[index].nrm.y = sin(theta) * sin(phi);
      mesh.verts[index].nrm.z = cos(theta);
    }
  }
  mesh.verts[static_cast<int64_t>(M) * (static_cast<int64_t>(size) - 1)].nrm = glm::vec3(0.0f, 0.0f, 1.0f);
  mesh.verts[(static_cast<int64_t>(M) * (static_cast<int64_t>(size) - 1) + 1)].nrm = glm::vec3(0.0f, 0.0f, -1.0f);

  for (unsigned n = 0; n < mesh.verts.size(); n++) {
    mesh.verts[n].pos = mesh.verts[n].nrm;
  }

  for (int i = 2; i < size; ++i)
    for (int j = 0; j < M; ++j)
    {
      const int jp1 = (j + 1) % M;
      mesh.indices.push_back(M * (i - 2) + j);
      mesh.indices.push_back(M * (i - 1) + jp1);
      mesh.indices.push_back(M * (i - 2) + jp1);

      mesh.indices.push_back(M * (i - 2) + j);
      mesh.indices.push_back(M * (i - 1) + j);
      mesh.indices.push_back(M * (i - 1) + jp1);
    }

  for (int j = 0; j < M; ++j)
  {
    const int jp1 = (j + 1) % M;
    mesh.indices.push_back(j);
    mesh.indices.push_back(jp1);
    mesh.indices.push_back(M * (size - 1));

    mesh.indices.push_back(M * (size - 2) + j);
    mesh.indices.push_back(M * (size - 1) + 1);
    mesh.indices.push_back(M * (size - 2) + jp1);
  }

  return newmesh;
}