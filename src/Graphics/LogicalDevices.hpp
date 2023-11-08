/*
    This class gets all the logical devices in your system anad selects the best one to use
*/
#pragma once
#include "../Helper.hpp"
#include <set>

class LogicalDevices
{
private:
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

public:
    VkQueue graphicsQueue = VK_NULL_HANDLE;
    VkQueue presentQueue = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE; 
    const std::vector<const char *> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    LogicalDevices(){};
    void Init();
    ~LogicalDevices();
};