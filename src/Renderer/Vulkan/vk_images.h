#pragma once 
/*!*****************************************************************************
\file     vk_images.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


#include <vulkan/vulkan.h>


namespace vkutil {

  void transition_image(VkCommandBuffer cmd, VkImage image, VkImageLayout currentLayout, VkImageLayout newLayout);

  void copy_image_to_image(VkCommandBuffer cmd, VkImage source, VkImage destination, VkExtent2D srcSize, VkExtent2D dstSize);

  void generate_mipmaps(VkCommandBuffer cmd, VkImage image, VkExtent2D imageSize);
} // namespace vkutil