#include "Events.h"
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

template<typename T>
Vector2<T>::Vector2(T xx, T yy)
{
	this->x = xx;
	this->y = yy;
}

template<typename T>
Vector2<T>::Vector2()
{
	this->x = 0;
	this->y = 0;
}

void Event::Callbacks::drop_callback(GLFWwindow* window, int count, const char** paths)
{
	std::string newPath = fs::current_path().string() + "\\Files\\";

	if (!fs::is_directory(newPath))
		fs::create_directory(newPath);

	for (int i = 0; i < count; i++)
	{
		std::string oldPath = paths[i];
		std::string fileName = oldPath.substr(oldPath.find_last_of("\\") + 1);

		fs::copy_file(oldPath, newPath + fileName);
	}
}

void Event::Callbacks::character_callback(GLFWwindow* window, unsigned int codepoint)
{
}

void Event::Callbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE)
		glfwDestroyWindow(window);
}

void Event::Callbacks::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

void Event::Callbacks::cursor_enter_callback(GLFWwindow* window, int entered)
{
	if (entered)
	{
		//Entered
	}
	else
	{
		//Left
	}
}

void Event::Callbacks::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		//Do Something
	}
}

void Event::key_init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Callbacks::key_callback);
}

void Event::character_init(GLFWwindow* window)
{
	glfwSetCharCallback(window, Callbacks::character_callback);
}

void Event::scroll_init(GLFWwindow* window)
{
	glfwSetScrollCallback(window, Callbacks::scroll_callback);
}

void Event::cursor_enter_init(GLFWwindow* window)
{
	glfwSetCursorEnterCallback(window, Callbacks::cursor_enter_callback);
}

void Event::mouse_button_init(GLFWwindow* window)
{
	glfwSetMouseButtonCallback(window, Callbacks::mouse_button_callback);
}

void Event::drop_init(GLFWwindow* window)
{
	glfwSetDropCallback(window, Callbacks::drop_callback);
}

Vector2d System::mouse_position(GLFWwindow* window)
{
	double posX, posY;
	glfwGetCursorPos(window, &posX, &posY);
	return Vector2d(posX, posY);
}
