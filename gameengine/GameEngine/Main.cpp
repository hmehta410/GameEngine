//GLEW_STATIC defined in visual studio project properties
#include "Game.h"

int main()
{
	Game game("Game Engine", 800, 600);
	game.run(); 
}