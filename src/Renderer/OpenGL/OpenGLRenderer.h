#pragma once
#include "..\RendererAPI.h"


class OpenGLRenderer :    public RendererAPI
{
public:
  virtual int Init() override;
  virtual void Clear() override;
  virtual void Shutdown() override;

private:



};

