#pragma once
#include <GLFW/glfw3.h>

template<typename T>
struct Vector2
{
public:
	Vector2(T x, T y);
	Vector2();
	T x, y;
};

typedef Vector2 <float> Vector2f;
typedef Vector2 <int> Vector2i;
typedef Vector2 <double> Vector2d;

namespace Event
{
	void key_init(GLFWwindow* window);
	void character_init(GLFWwindow* window);
	void scroll_init(GLFWwindow* window);
	void cursor_enter_init(GLFWwindow* window);
	void mouse_button_init(GLFWwindow* window);
	void drop_init(GLFWwindow* window);

	namespace Callbacks
	{
		void drop_callback(GLFWwindow* window, int count, const char** paths);
		void character_callback(GLFWwindow* window, unsigned int codepoint);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		void cursor_enter_callback(GLFWwindow* window, int entered);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	}
}

namespace System
{
	Vector2d mouse_position(GLFWwindow* window);
}
