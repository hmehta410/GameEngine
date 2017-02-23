#include "Assert.h"

#include "GL\glew.h"
#include "Keyboard.h"

Keyboard::Keyboard(GLFWwindow* window) : window(window)
{
	for (int i = 0; i < numKeys; i++)
	{
		keyIsPressed[i] = false;
	}
}

// Use this to read keyboard
bool Keyboard::GetKeyState( AZUL_KEY key)
{
	return (glfwGetKey(this->window, key) == GLFW_PRESS);
}

bool Keyboard::IsOnKeyPress(AZUL_KEY key)
{
	if (glfwGetKey(this->window, key) == GLFW_RELEASE && keyIsPressed[key])
	{
		keyIsPressed[key] = false;
	}
	else if (glfwGetKey(this->window, key) == GLFW_PRESS && !keyIsPressed[key])
	{
		keyIsPressed[key] = true;
		return true;
	}
	return false;
}

bool Keyboard::IsOnKeyRelease(AZUL_KEY key)
{
	if (glfwGetKey(this->window, key) == GLFW_RELEASE && keyIsPressed[key])
	{
		keyIsPressed[key] = false;
		return true;
	}
	else if (glfwGetKey(this->window, key) == GLFW_PRESS && !keyIsPressed[key])
	{
		keyIsPressed[key] = true;
	}
	return false;
}
