#include <stdlib.h>
#include "Assert.h"
#include <cstring>
#include "File\File.h"
#include "GL\glew.h"
#include "List\LinkedIterator.h"
#include "Texture.h"
#include "TextureManager.h"
#include <memory>


namespace
{
	// Define targa header
#pragma pack(1)
	typedef struct
	{
		GLbyte	identsize;              // Size of ID field that follows header (0)
		GLbyte	colorMapType;           // 0 = None, 1 = paletted
		GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
		unsigned short	colorMapStart;          // First colour map entry
		unsigned short	colorMapLength;         // Number of colors
		unsigned char 	colorMapBits;   // bits per palette entry
		unsigned short	xstart;                 // image x origin
		unsigned short	ystart;                 // image y origin
		unsigned short	width;                  // width in pixels
		unsigned short	height;                 // height in pixels
		GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
		GLbyte	descriptor;             // image descriptor
	} TGAHEADER;
#pragma pack(8)


	////////////////////////////////////////////////////////////////////
	// read targa bits. Returns pointer to buffer,
	// height, and width of texture, and the OpenGL format of data.
	// This only works on pretty vanilla targas... 8, 24, or 32 bit color
	// only, no palettes, no RLE encoding.
	GLbyte *ParseTGABufferIntoGLBytes(const char *buffer, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat)
	{
		//FILE *pFile;			// File pointer
		TGAHEADER* tgaHeader;		// TGA file header
		unsigned long lImageSize;		// Size in bytes of image
		short sDepth;			// Pixel depth;
		GLbyte	*pBits = NULL;          // Pointer to bits

		// Default/Failed values
		*iWidth = 0;
		*iHeight = 0;
		*eFormat = GL_RGB;
		*iComponents = GL_RGB;

		//cast buffer as header. Luckily buffer lives longer than header 
		tgaHeader = (TGAHEADER*)buffer;

		// Get width, height, and depth of texture
		*iWidth = tgaHeader->width;
		*iHeight = tgaHeader->height;
		sDepth = tgaHeader->bits / 8;

		// Put some validity checks here. Very simply, I only understand
		// or care about 8, 24, or 32 bit targa's.
		if (tgaHeader->bits != 8 && tgaHeader->bits != 24 && tgaHeader->bits != 32)
			return NULL;

		// Calculate size of image buffer
		lImageSize = tgaHeader->width * tgaHeader->height * sDepth;

		//pBits points into the buffer. buffer will need to live longer than pBits.
		pBits = (GLbyte*)(buffer + sizeof(TGAHEADER));

		// Set OpenGL format expected
		switch (sDepth)
		{

		case 3:     // Most likely case
			*eFormat = GL_BGR;
			*iComponents = GL_RGB;
			break;

		case 4:
			*eFormat = GL_BGRA;
			*iComponents = GL_RGBA;
			break;
		case 1:
			assert(false);
			//*eFormat = GL_LUMINANCE;
			//*iComponents = GL_LUMINANCE;
			break;
		default:        // RGB
			// If on the iPhone, TGA's are BGR, and the iPhone does not 
			// support BGR without alpha, but it does support RGB,
			// so a simple swizzle of the red and blue bytes will suffice.
			// For faster iPhone loads however, save your TGA's with an Alpha!

			break;
		}

		// Return pointer to image data
		return pBits;
	}

	//turn the buffer data into opengl texture
	GLuint GenerateGLTexture(const char *buffer, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
	{
		// Get an opengl ID for textures
		GLuint textureID;
		glGenTextures(1, &textureID);

		// Bind it.
		glBindTexture(GL_TEXTURE_2D, textureID);
		
		int nWidth, nHeight, nComponents;
		GLenum eFormat;

		//parse the texture bits from the buffer into a format suitable for opengl
		GLbyte *pBits = ParseTGABufferIntoGLBytes(buffer, &nWidth, &nHeight, &nComponents, &eFormat);
		assert(pBits != NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBits);

		if (minFilter == GL_LINEAR_MIPMAP_LINEAR ||
			minFilter == GL_LINEAR_MIPMAP_NEAREST ||
			minFilter == GL_NEAREST_MIPMAP_LINEAR ||
			minFilter == GL_NEAREST_MIPMAP_NEAREST)
			glGenerateMipmap(GL_TEXTURE_2D);

		return textureID;
	}
}

//A node class to hold textures and place them in the linked list
struct TextureMan::TextureNode : public DLink
{
	String name;
	Texture texture;
};

TextureMan::TextureMan()
{
}

TextureMan::~TextureMan()
{
	this->DeleteTextures();
}

TextureMan* TextureMan::GetInstance()
{
	static TextureMan textMan;
	return &textMan;
}

Texture* TextureMan::LoadTexture(const char * const fileName)
{
	//check if we already loaded it once before
	Texture* texture = TextureMan::Find(fileName);

	//if (we didn't load it before)
	if (texture == nullptr)
	{
		//read file into buffer
		File file(fileName, FileMode::READ);
		int fileSize = file.GetSize();

		std::unique_ptr<char[]> buffer(new char[fileSize]);
		file.Read(buffer.get(), fileSize);

		//set some opengl texture settings
		GLenum minFilter = GL_LINEAR;
		GLenum magFilter = GL_LINEAR;
		GLenum wrapMode = GL_CLAMP_TO_EDGE;

		//turn buffer data into opengl texture
		GLuint textureID = GenerateGLTexture(buffer.get(), minFilter, magFilter, wrapMode);

		//create texture node
		TextureNode* node = new TextureNode();
		node->name = fileName;

		//set texture values
		texture = &node->texture;
		texture->set(textureID, minFilter, magFilter, wrapMode);

		//push texture node into pool
		TextureMan *man = TextureMan::GetInstance();
		man->textures.PushBack(node);
	}
	return texture;
}

Texture* TextureMan::Find(const char* assetName)
{
	TextureMan *man = TextureMan::GetInstance();

	LinkedIterator it = man->textures.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		TextureNode* node = (TextureNode*)link;
		if( node->name == assetName )
		{
			return &node->texture;
		}
	}

	return nullptr;
}

void TextureMan::DeleteTextures( )
{
	TextureMan *man = TextureMan::GetInstance();
	man->textures.DeleteList();
}
