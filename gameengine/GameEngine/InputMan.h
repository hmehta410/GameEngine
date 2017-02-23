#ifndef SUPER_INPUT_MAN_H
#define SUPER_INPUT_MAN_H

#include "Keyboard.h"
#include "Mouse.h"
#include "GLFW\glfw.h"
#include <memory>

//gives static access to keyboard and mouse
class InputMan
{
public:
	static void Initialize(GLFWwindow* window);
	static Keyboard *GetKeyboard();
	static Mouse *GetMouse();
	static void SetWindowSize(int width, int height);

private:
	InputMan();
	static InputMan* GetInstance();
	
	// Data
	std::unique_ptr<Keyboard>	keyboard;
	std::unique_ptr<Mouse>		mouse;
};
#endif