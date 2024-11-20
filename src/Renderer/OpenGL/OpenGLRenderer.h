#pragma once
/*!*****************************************************************************
\file     OpenGlRenderer.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/

#include "..\RendererAPI.h"

namespace Engine {

  class OpenGLRenderer :    public RendererAPI
  {
  public:
    virtual int Init() override;
    virtual void Clear() override;
    virtual void Shutdown() override;

  private:



  };


}
