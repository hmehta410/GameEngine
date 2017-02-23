#pragma once

#include "GL\glew.h"
#include "GLFW/glfw.h"
#include "Time\Time.h"
#include <thread>
#include <mutex>
#include <condition_variable>

class Engine
{
public:
	Engine(const char* windowName, int width, int height);
	virtual ~Engine();

	virtual void Initialize() = 0;
	virtual void LoadContent() = 0;
	virtual void Update(float currentTime) = 0;
	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void UnloadContent() = 0;

	virtual void ClearBufferFunc();

	void run();
private:

	void preInitialize();
	void preLoadContent();

public:
	virtual void onResize(int w, int h);
	virtual void onKey(int key, int action);
	virtual void onMouseButton(int button, int action);
	virtual void onMouseMove(double xPos, double yPos);
	virtual void onMouseWheel(double xOffset, double yOffset);
	virtual void onDebugMessage(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message);
	static void getMousePosition(int& x, int& y);

public:
	struct APPINFO
	{
		static const int kTitleLength = 128;
		GLFWwindow* window;
		char title[kTitleLength];
		int windowWidth;
		int windowHeight;
		int majorVersion;
		int minorVersion;
		int samples;
#pragma warning( disable : 4201)
		union
		{
			struct
			{
				unsigned int    fullscreen : 1;
				unsigned int    vsync : 1;
				unsigned int    cursor : 1;
				unsigned int    stereo : 1;
				unsigned int    debug : 1;
			};
			unsigned int        all;
		} flags;
	};

protected:
	APPINFO     info;
	Time		time_in_seconds;
	static      Engine * app;
	std::mutex	mutex;
	std::condition_variable cv;

	static void glfw_onResize(GLFWwindow* window, int w, int h);
	static void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void glfw_onMouseButton(GLFWwindow* window, int button, int action, int mods);
	static void glfw_onMouseMove(GLFWwindow* window, double xpos, double ypos);
	static void glfw_onMouseWheel(GLFWwindow* window, double xoffset, double yoffset);
	void setVsync(bool enable);
	static void APIENTRY debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const GLvoid* userParam);
private:
};

