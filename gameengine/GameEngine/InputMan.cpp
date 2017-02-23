#include "Assert.h"
#include "InputMan.h"

InputMan::InputMan()
	:keyboard(nullptr), mouse(nullptr)
{
}

void InputMan::Initialize(GLFWwindow* window)
{
	assert(GetInstance()->keyboard == nullptr);
	assert(GetInstance()->mouse == nullptr);

	InputMan* input = GetInstance();
	input->keyboard.reset(new Keyboard(window));
	input->mouse.reset(new Mouse(window));
}

Keyboard *InputMan::GetKeyboard()
{
	assert(GetInstance()->keyboard != nullptr);
	return GetInstance()->keyboard.get();
}

Mouse *InputMan::GetMouse()
{
	assert(GetInstance()->mouse != nullptr);
	return GetInstance()->mouse.get();
}

InputMan* InputMan::GetInstance()
{
	static InputMan singleton;
	return &singleton;
}

void InputMan::SetWindowSize(int width, int height)
{
	Mouse* mouse = GetInstance()->mouse.get();
	mouse->SetWindowWidth(width);
	mouse->SetWindowHeight(height);
}
