#include "CameraControls.h"

#include "GL\glew.h"
#include "InputMan.h"
#include "CameraMan.h"

void UpdateCameraControls()
{
	Keyboard* board = InputMan::GetKeyboard();
	Mouse* mouse = InputMan::GetMouse();
	if (board->GetKeyState(KEY_LEFT_ALT))
	{
		static float xPos = 0.0f;
		static float yPos = 0.0f;

		//this first set of OnKeyPress's initialize the cursor point for 
		//calculating the distance the cursor moves
		if (mouse->IsOnKeyPress(AZUL_MOUSE::BUTTON_LEFT))
		{
			mouse->GetCursor(xPos, yPos);
		}
		if (mouse->IsOnKeyPress(AZUL_MOUSE::BUTTON_MIDDLE))
		{
			mouse->GetCursor(xPos, yPos);
		}
		if (mouse->IsOnKeyPress(AZUL_MOUSE::BUTTON_RIGHT))
		{
			mouse->GetCursor(xPos, yPos);
		}



		if (mouse->GetKeyState(AZUL_MOUSE::BUTTON_LEFT)) //rotate
		{
			float prevX = xPos;
			float prevY = yPos;
			mouse->GetCursor(xPos, yPos);

			Camera* cam = CameraMan::GetActive();
			Vect pos;
			Vect tar;
			Vect up;
			Vect upNorm;
			Vect forwardNorm;
			Vect rightNorm;

			cam->GetNormalsAndPoints(up, tar, pos, upNorm, forwardNorm, rightNorm);

			//lateral rotation always happens around the y-axis to give a sense of stability
			Matrix RotLat(ROT_AXIS_ANGLE, Vect(0, 1, 0), 5 * (prevX - xPos));
			//everything works well unless rightNorm is close to y-axis, then gimbal lock...
			Matrix RotVert(ROT_AXIS_ANGLE, rightNorm, 5 * (prevY - yPos));

			Matrix M = RotVert * RotLat;

			upNorm *= M;
			pos = ((pos-tar) * M) + tar;

			cam->SetOrientAndPosition(upNorm, tar, pos);
		}
		else if (mouse->GetKeyState(AZUL_MOUSE::BUTTON_MIDDLE)) //pan
		{
			float prevX = xPos;
			float prevY = yPos;
			mouse->GetCursor(xPos, yPos);

			Camera* cam = CameraMan::GetActive();
			Vect up, pos, dir, tar, right;
			cam->GetDirection(dir);
			cam->GetPosition(pos);
			right = cam->GetRightNormal();
			cam->GetUp(up);
			cam->GetLookAt(tar);

			//the more zoomed in you are the less panning effect
			Vect deltaMove = (-right*(xPos - prevX) + up*(yPos - prevY)) * (tar-pos).Magnitude();

			cam->SetOrientAndPosition(up, tar + deltaMove, pos + deltaMove);
		}
		else if (mouse->GetKeyState(AZUL_MOUSE::BUTTON_RIGHT)) // zoom
		{
			float prevX = xPos;
			mouse->GetCursor(xPos, yPos);

			Camera* cam = CameraMan::GetActive();
			Vect up, pos, dir, tar;
			cam->GetDirection(dir);
			cam->GetPosition(pos);
			cam->GetUp(up);
			cam->GetLookAt(tar);

			//the more zoomed in you are the less the zoom effect. 
			cam->SetOrientAndPosition(up, tar, pos + dir*(xPos - prevX) * (tar - pos).Magnitude());
		}
	}

	//TODO: scroll wheel callback function for zooming
}