#pragma once
/*!*****************************************************************************
\file     RendererApi.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/



class RendererAPI
{
public: 
  virtual ~RendererAPI() = default;

  virtual int Init() = 0;
  virtual void Clear() = 0;
  virtual void Shutdown() = 0;


};

