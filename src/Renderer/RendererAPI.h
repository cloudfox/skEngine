#pragma once



class RendererAPI
{
public: 
  virtual ~RendererAPI() = default;

  virtual int Init() = 0;
  virtual void Clear() = 0;
  virtual void Shutdown() = 0;


};

