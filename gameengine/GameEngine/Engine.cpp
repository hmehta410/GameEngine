#include "Engine.h"
#include <stdio.h>
#include <string.h>
#include "Assert.h"
#include <limits>

//static instance made available for easy use in callbacks
Engine * Engine::app = 0;

Engine::Engine(const char* windowName, int width, int height)
	:time_in_seconds(Duration::TIME_ONE_SECOND)
{
	static_assert(std::numeric_limits<float>::is_iec559, "The float representation is not IEEE compliant. Many of the operations used in this engine assume IEEE compliance.");
	strncpy_s(info.title, APPINFO::kTitleLength, windowName, APPINFO::kTitleLength - 1);
	info.windowWidth = width;
	info.windowHeight = height;

	//TODO move info values into settings file which read in Initialize()
	info.majorVersion = 4;
	info.minorVersion = 0;

	info.samples = 0;
	info.flags.all = 0;
	info.flags.cursor = 1;

#ifdef _DEBUG
	info.flags.debug = 1;
#endif
}

Engine::~Engine()
{
}

void Engine::ClearBufferFunc()
{
	const GLfloat grey[] = { 0.250f, 0.25f, 0.25f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, grey);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

void Engine::preInitialize()
{
	app = this;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		assert(false);
	}
}

bool isExtensionSupported(const char * extname)
{
	GLint numExtensions;
	GLint i;

	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

	for (i = 0; i < numExtensions; i++)
	{
		const GLubyte * e = glGetStringi(GL_EXTENSIONS, i);
		if (!strcmp((const char *)e, extname))
		{
			return true;
		}
	}

	return false;
}

void Engine::preLoadContent()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, info.majorVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, info.minorVersion);

#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif /* _DEBUG */

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, info.samples);
	glfwWindowHint(GLFW_STEREO, info.flags.stereo ? GL_TRUE : GL_FALSE);

	if (info.flags.fullscreen)
	{
		if (info.windowWidth == 0 || info.windowHeight == 0)
		{
			const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			info.windowWidth = mode->width;
			info.windowHeight = mode->height;
		}
		info.window = glfwCreateWindow(info.windowWidth, info.windowHeight, info.title, glfwGetPrimaryMonitor(),nullptr);
		glfwSwapInterval((int)info.flags.vsync);
	}
	else
	{
		info.window = glfwCreateWindow(info.windowWidth, info.windowHeight, info.title, nullptr, nullptr);
		assert(info.window != nullptr);		
	}

	glfwMakeContextCurrent(info.window);
	glfwSetWindowSizeCallback(info.window, glfw_onResize);
	glfwSetKeyCallback(info.window, glfw_onKey);
	glfwSetMouseButtonCallback(info.window, glfw_onMouseButton);
	glfwSetCursorPosCallback(info.window, glfw_onMouseMove);
	glfwSetScrollCallback(info.window, glfw_onMouseWheel);
	glfwSetInputMode(info.window, GLFW_CURSOR, (info.flags.cursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED));

	info.flags.stereo = (glfwGetWindowAttrib(info.window, GLFW_STEREO) ? 1 : 0);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	assert(GLEW_OK == err);

#ifdef _DEBUG
	fprintf(stderr, "VENDOR: %s\n", (char *)glGetString(GL_VENDOR));
	fprintf(stderr, "VERSION: %s\n", (char *)glGetString(GL_VERSION));
	fprintf(stderr, "RENDERER: %s\n", (char *)glGetString(GL_RENDERER));
#endif

	if (info.flags.debug)
	{
		if (glewIsSupported("GL_VERSION_4_3"))
		{
			glDebugMessageCallback(debug_callback, this);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		}
		else if (isExtensionSupported("GL_ARB_debug_output"))
		{
			glDebugMessageCallbackARB(debug_callback, this);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		}
	}

	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

}

void Engine::run()
{
	this->preInitialize();

	Initialize();   // Virtual

	this->preLoadContent();

	LoadContent();  // Virtual

	float lastTime = 0;
	while ((glfwGetKey(info.window, GLFW_KEY_ESCAPE) == GLFW_RELEASE))
	{
		ClearBufferFunc();

		float time = (float)glfwGetTime();
		Update(time - lastTime);
		lastTime = time;

		// rendering on main thread
		Draw();

		Clean();
		glfwSwapBuffers(info.window);
		glfwPollEvents();
	}

	UnloadContent();

	glfwTerminate();
}

void Engine::glfw_onResize(GLFWwindow* window, int w, int h)
{
	window;
	app->onResize(w, h);
}

void Engine::glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	window;
	scancode;
	mods;
	app->onKey(key, action);
}

void Engine::glfw_onMouseButton(GLFWwindow* window, int button, int action, int mods)
{
	window;
	mods;
	app->onMouseButton(button, action);
}

void Engine::glfw_onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
	window;
	app->onMouseMove(xpos, ypos);
}

void Engine::glfw_onMouseWheel(GLFWwindow* window, double xoffset, double yoffset)
{
	window;
	app->onMouseWheel(xoffset, yoffset);
}

void Engine::setVsync(bool enable)
{
	info.flags.vsync = enable ? 1 : 0;
	glfwSwapInterval((int)info.flags.vsync);
}

void APIENTRY Engine::debug_callback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const GLvoid* userParam)
{
	((Engine*)userParam)->onDebugMessage(source, type, id, severity, length, message);
}

void Engine::onResize(int w, int h)
{
	info.windowWidth = w;
	info.windowHeight = h;
}

void Engine::onKey(int key, int action)
{
	key;//not used
	action;//not used
}

void Engine::onMouseButton(int button, int action)
{
	button;//not used
	action;//not used
}

void Engine::onMouseMove(double x, double y)
{
	x; /*not used*/
	y;/* not used*/
}

void Engine::onMouseWheel(double xOffset, double yOffset)
{
	xOffset; /*not used*/
	yOffset;
}

void Engine::onDebugMessage(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message)
{
	fprintf(stderr, "%s\n",message);

	type;
	id;
	severity;
	length;

	source;
}