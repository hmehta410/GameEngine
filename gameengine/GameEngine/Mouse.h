#ifndef MOUSE_H
#define MOUSE_H

#include "GLFW/glfw.h"

// Wrapper to buffer users from the internal glfw driver
// Converted to enumeration for type safety

enum AZUL_MOUSE
{
	BUTTON_1 = 0,
	BUTTON_2 = 1,
	BUTTON_3 = 2,
	BUTTON_4 = 3,
	BUTTON_5 = 4,
	BUTTON_6 = 5,
	BUTTON_7 = 6,
	BUTTON_8 = 7,
	BUTTON_LEFT = GLFW_MOUSE_BUTTON_1,
	BUTTON_RIGHT = GLFW_MOUSE_BUTTON_2,
	BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_3
};

class Mouse
{
public:
	Mouse(GLFWwindow* window);

	// Use this to read mouse buttons
	bool GetKeyState(AZUL_MOUSE button);
	bool IsOnKeyPress(AZUL_MOUSE key);
	bool IsOnKeyRelease(AZUL_MOUSE key);

	// get cursor
	void GetCursor(float &xPos, float &yPos); 
	void SetWindowWidth(int width);
	void SetWindowHeight(int height);

private:
	static const int numKeys = 11;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;

	bool keyIsPressed[numKeys];
};


#endif