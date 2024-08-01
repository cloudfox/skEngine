#pragma once
#include "..\RendererAPI.h"



class VulkanRenderer : public RendererAPI
{

public:
  virtual int Init() override;
  virtual void Clear() override;
  virtual void Shutdown() override;


  

private:
  //VkInstance instance_;
  //vkb::InstanceDispatchTable instDisp_;
  //VkSurfaceKHR surface_;
  //vkb::Device device_;
  //vkb::DispatchTable disp_;
  //vkb::Swapchain swapchain_;
  //
  int SetupVulkan();

  int DeviceInitialization();




};


