#include "Game.h"
#include "InputMan.h"
#include "BoneAnimationScene.h"
#include "ModelViewerScene.h"
#include "CameraMan.h"
#include "ShaderMan.h"
#include "SkinnedAnimationScene.h"

Game::Game(const char* windowName, int width, int height)
	:Engine(windowName, width, height)
{
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	InputMan::Initialize(this->info.window);
	InputMan::SetWindowSize(info.windowWidth, info.windowHeight);
	//this->scene.reset(new ModelViewerScene(this->info.windowWidth, this->info.windowHeight));
	this->scene.reset(new BoneAnimationScene(this->info.windowWidth, this->info.windowHeight));
	//this->scene.reset(new SkinnedAnimationScene(this->info.windowWidth, this->info.windowHeight));
}

float lastTime = 0.0f;

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, transformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	scene->Update(currentTime);
	CameraMan::Update(currentTime);
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	scene->Draw(0.0);
}

//-----------------------------------------------------------------------------
// Game::Clean()
//		This function is called once per frame
//	    Used for cleaning up data marked for delete
//-----------------------------------------------------------------------------
void Game::Clean()
{
	scene->Clean();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnloadContent()
{
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat blue[] = { 0.4f, 0.4f, 0.8f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, blue);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

void Game::onResize(int w, int h)
{
	Engine::onResize(w, h);
	InputMan::SetWindowSize(w, h);
}
