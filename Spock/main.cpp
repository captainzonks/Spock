#include "SpockHeaders.h"

int main()
{
	// Create Window
	Window ourWindow{};
	ourWindow.initWindow("Spock Application", 800, 600);

	// Create Vulkan Renderer instance
	VulkanRenderer ourRenderer{};
	if (ourRenderer.init(ourWindow.GetWindow()) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}

	// Loop until closed
	while (!glfwWindowShouldClose(ourWindow.GetWindow()))
	{
		glfwPollEvents();
	}

	ourRenderer.cleanup();

	// Destroy GLFW window and stop GLFW
	glfwDestroyWindow(ourWindow.GetWindow());
	glfwTerminate();

	return 0;
}
