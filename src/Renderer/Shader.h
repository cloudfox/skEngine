#pragma once
#include <string>
/*!*****************************************************************************
\file     Shader.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


class Shader
{
public:
  Shader(const char* vertexPath, const char* fragmentPath);

public:
  void Use();
  int ID();

  //Shader Uniform functions
  void SetBool(const std::string& name, bool value) const;
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;
  //void SetMat4(const std::string& name, ) const;

private:
  unsigned int ID_{};

  void checkCompileErrors(unsigned int shader, std::string type);

};

