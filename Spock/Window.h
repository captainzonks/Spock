#pragma once

#include "SpockHeaders.h"

class Window
{
public:
	void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600);

	GLFWwindow* GetWindow() const { return window; }

private:
	GLFWwindow* window;
};
