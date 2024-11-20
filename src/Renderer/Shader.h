#pragma once
#include <string>
#include <glm/vec3.hpp>
/*!*****************************************************************************
\file     Shader.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


class Shader
{
public:
  Shader();
  void load(const char* vertexPath, const char* fragmentPath);
  void use();
  int ID();

  //Shader Uniform functions
  void SetBool(const std::string& name, bool value) const;
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;
  void SetVec3(const std::string& name, const glm::vec3& value) const;
  //void SetMat4(const std::string& name, ) const;

private:
  unsigned int ID_{};

  void checkCompileErrors(unsigned int shader, std::string type);
};

