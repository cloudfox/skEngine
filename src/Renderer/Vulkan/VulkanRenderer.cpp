#include "VulkanRenderer.h"

#include <chrono>
#include <thread>
#include <array>
#include <iostream>

#include <vulkan/vulkan_core.h>
#include "GLFW/glfw3.h"



#include "vk_types.h"
#include "vk_initializers.h"
#include "vk_images.h"

#include "../Renderer.h"


const int MAX_FRAMES_IN_FLIGHT = 2;


int VulkanRenderer::Init()
{
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  Renderer::window_s = glfwCreateWindow(1280, 720, "SK Engine - Vulkan", nullptr, nullptr);

  SetupVulkan();
}

int VulkanRenderer::SetupVulkan()
{
  //Instatiate Vk Builder
  ///////////////////////

  vkb::InstanceBuilder builder;
  

  //if (0 != device_initialization(init)) return -1;
  //if (0 != create_swapchain(init)) return -1;
  //if (0 != get_queues(init, render_data)) return -1;
  //if (0 != create_render_pass(init, render_data)) return -1;
  //if (0 != create_graphics_pipeline(init, render_data)) return -1;
  //if (0 != create_framebuffers(init, render_data)) return -1;
  //if (0 != create_command_pool(init, render_data)) return -1;
  //if (0 != create_command_buffers(init, render_data)) return -1;
  //if (0 != create_sync_objects(init, render_data)) return -1;




  //Configure Vk Builder
  /////////////////////////
  


  
}

//VkSurfaceKHR create_surface_glfw(VkInstance instance, GLFWwindow* window, VkAllocationCallbacks* allocator = nullptr) {
//  VkSurfaceKHR surface = VK_NULL_HANDLE;
//  VkResult err = glfwCreateWindowSurface(instance, window, allocator, &surface);
//  if (err) {
//    const char* error_msg;
//    int ret = glfwGetError(&error_msg);
//    if (ret != 0) {
//      std::cout << ret << " ";
//      if (error_msg != nullptr) std::cout << error_msg;
//      std::cout << "\n";
//    }
//    surface = VK_NULL_HANDLE;
//  }
//  return surface;
//}
//
//struct Init {
//  GLFWwindow* window;
//  vkb::Instance instance;
//  vkb::InstanceDispatchTable inst_disp;
//  VkSurfaceKHR surface;
//  vkb::Device device;
//  vkb::DispatchTable disp;
//  vkb::Swapchain swapchain;
//};
//
//int VulkanRenderer::DeviceInitialization()
//{
//
//  vkb::InstanceBuilder instance_builder;
//  auto instance_ret = instance_builder.use_default_debug_messenger().request_validation_layers().build();
//  if (!instance_ret) {
//    std::cout << instance_ret.error().message() << "\n";
//    return -1;
//  }
//  instance_ = instance_ret.value();
//
// //instDisp_ = instance_.make_table();  //what the fuck
//
//  surface_ = create_surface_glfw(instance_, Renderer::window_s);
//
//  //vkb::PhysicalDeviceSelector phys_device_selector(instance_);
//  //vkb::PhysicalDeviceSelector selector{ instance_ };
//
//  auto phys_device_ret = phys_device_selector.set_surface(surface_).select();
//  if (!phys_device_ret) {
//    std::cout << phys_device_ret.error().message() << "\n";
//    return -1;
//  }
//  vkb::PhysicalDevice physical_device = phys_device_ret.value();
//
//  vkb::DeviceBuilder device_builder{ physical_device };
//  auto device_ret = device_builder.build();
//  if (!device_ret) {
//    std::cout << device_ret.error().message() << "\n";
//    return -1;
//  }
//  device_ = device_ret.value();
//
//  disp_ = device_.make_table();
//
//  return 0;
//
//
//  return 0;
//}
//




void VulkanRenderer::Shutdown()
{
  glfwDestroyWindow(Renderer::window_s);
  glfwTerminate();
}


void VulkanRenderer::Clear()
{
}




