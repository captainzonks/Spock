#pragma once

#include "SpockHeaders.h"
#include "Utilities.h"

class VulkanRenderer
{
public:

	VulkanRenderer();
	~VulkanRenderer();

	int init(GLFWwindow* newWindow);
	void cleanup();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;
	struct {
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;
	VkQueue graphicsQueue;
	VkQueue presentationQueue;
	VkSurfaceKHR surface;

	////////// Vulkan Functions //////////
	//////////////////////////////////////
	
	// Creation Functions
	void createInstance();
	void createLogicalDevice();
	void createSurface();

	// Get Functions
	void getPhysicalDevice();

	// Support Functions

	//// Checker Functions
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	//// Getter Functions
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
	SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);
};
