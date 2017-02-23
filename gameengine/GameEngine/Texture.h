#ifndef TEXTURE_NODE_H
#define TEXTURE_NODE_H

#include "GL\glew.h"
#include "List\Link.h"
#include "String\String.h"

//A class that contains the opengl texture settings and id.
//It is usually passed to a shader where the textureID is bound
//using glBindTexture(GL_TEXTURE_2D, textureID);
//A texture will delete its gl textureID on destruction
//A texture can only be created by the TextureMan
class Texture
{
public:
	~Texture();
	
	//no copies will ensure that we don't delete the glTexture twice
	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;

	GLuint GetTextureID() const { return textureID; }
	GLenum GetMinFilter() const { return minFilter; }
	GLenum GetMagFilter() const { return magFilter; }
	GLenum GetWrapMode() const { return wrapMode; }

private:
	Texture();
	void set(GLuint _TextureID,
		GLenum minFilter,
		GLenum magFilter,
		GLenum wrapMode);

	GLuint textureID;
	GLenum minFilter;
	GLenum magFilter;
	GLenum wrapMode;

	friend class TextureMan;
};



#endif