#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "GL\glew.h"
#include "Texture.h" 
#include "List\DList.h"

/*
This class manages Textures. Each texture represents a texture on the gpu and
the manager serves as a way to ensure that the same texture file is not created
twice on the gpu and that textures are not deleted prematurely.
*/
class TextureMan
{
public:
	~TextureMan();

	static Texture* LoadTexture(const char* const fileName);
	static Texture* Find(const char * const fileName);

	static void DeleteTextures();

private:  
	TextureMan();
	static TextureMan *GetInstance();

	struct TextureNode; //type placed in textures list

	DList textures; //type TextureNode
};

#endif