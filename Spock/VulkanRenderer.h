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

	////////// Vulkan Functions //////////
	//////////////////////////////////////
	
	// Creation Functions
	void createInstance();
	void createLogicalDevice();

	// Get Functions
	void getPhysicalDevice();

	// Support Functions

	//// Checker Functions
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	//// Getter Functions
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};
