#include "Texture.h"
#include "GL\glew.h"

Texture::Texture()
: textureID(0), minFilter(GL_LINEAR), magFilter(GL_LINEAR), wrapMode(GL_CLAMP_TO_EDGE)
{
}

Texture::~Texture()
{
	//silently ignores zeros
	glDeleteTextures(1, &this->textureID);
}

void Texture::set(		GLuint _TextureID, 
						GLenum _minFilter, 
						GLenum _magFilter, 
						GLenum _wrapMode)
{
	this->magFilter = _magFilter;
	this->minFilter = _minFilter;
	this->wrapMode = _wrapMode;
	this->textureID =_TextureID;
}

