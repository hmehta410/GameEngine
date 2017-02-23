#include "Assert.h"
#include "Mouse.h"
#include <stdio.h>

Mouse::Mouse(GLFWwindow* window)
	:window(window)
{
}

bool Mouse::GetKeyState(AZUL_MOUSE button)
{
	return (glfwGetMouseButton(this->window, button) == GLFW_PRESS);
}


void Mouse::SetWindowWidth(int width)
{
	windowWidth = width;
}

void Mouse::SetWindowHeight(int height)
{
	windowHeight = height;
}

void Mouse::GetCursor(float &xPos, float &yPos)
{
	double xInt;
	double yInt;

	// get mouse position
	glfwGetCursorPos(this->window, &xInt, &yInt);

	xPos = ((float)xInt) / windowWidth;
	yPos = ((float)yInt) / windowHeight;
}

bool Mouse::IsOnKeyPress(AZUL_MOUSE button)
{
	if (glfwGetMouseButton(this->window, button) == GLFW_PRESS && !keyIsPressed[button])
	{
		int count = 0;
		if (button == BUTTON_LEFT)
		{
			count++;
		}
		keyIsPressed[button] = true;
		return true;
	}
	else if (glfwGetKey(this->window, button) == GLFW_RELEASE && keyIsPressed[button])
	{
		keyIsPressed[button] = false;
	}
	return false;
}

bool Mouse::IsOnKeyRelease(AZUL_MOUSE button)
{
	if (glfwGetMouseButton(this->window, button) == GLFW_PRESS && !keyIsPressed[button])
	{
		keyIsPressed[button] = true;
	}
	else if (glfwGetKey(this->window, button) == GLFW_RELEASE && keyIsPressed[button])
	{
		keyIsPressed[button] = false;
		return true;
	}
	return false;
}