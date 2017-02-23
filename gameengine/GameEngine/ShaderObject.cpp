#include "ShaderObject.h"
#include <math.h>
#include "Assert.h"

#include "Math\MathEngine.h"
#include "File\File.h"
#include "Game.h"
#include "GL\glew.h"

ShaderObject::~ShaderObject()
{
	glDeleteShader(this->fragShader);
	glDeleteShader(this->vertShader);
	glDeleteProgram(this->programObject);
}

ShaderObject::ShaderObject(const char * shaderBaseFileName) 
	: programObject(0), fragShader(0), vertShader(0)
{
	shaderName = shaderBaseFileName;
	assert( shaderBaseFileName != 0 );
	this->CreateVertFragShader(shaderBaseFileName, shaderBaseFileName);
}

GLuint ShaderObject::GetUniformLocation( const char * uniformName) const
{
	assert( uniformName != 0 );
	GLuint loc =  glGetUniformLocation(this->programObject, uniformName );

	assert(loc != -1);
	return loc;
}

GLuint ShaderObject::GetUniformBlockIndex(const char* blockName) const
{
	assert(blockName != 0);
	GLuint loc = glGetUniformBlockIndex(this->programObject, blockName);

	assert(loc != -1);
	return loc;
}

GLuint ShaderObject::GetProgramObject() const
{
	return this->programObject;
}

void ShaderObject::UseProgram() const
{
	glUseProgram(this->programObject);
}

const String& ShaderObject::GetName() const
{
	return shaderName;
}

namespace
{
	bool LoadNCompile(GLuint &shaderObject, const char * const shaderFileName, GLenum shader_type)
	{
		//read file into buffer
		File file(shaderFileName, FileMode::READ);
		FileError ferror = file.GetError();
		assert(FileError::NONE == ferror);

		int numBytesInFile = file.GetSize();

		char *data = new char[numBytesInFile + 1];
		file.Read(data, numBytesInFile);

		// null termination character
		data[numBytesInFile] = 0;

		file.Close();
		assert(FileError::NONE == file.GetError());

		// create a shader object
		shaderObject = glCreateShader(shader_type);
		assert(shaderObject != 0);

		//load shader
		glShaderSource(shaderObject, 1, &data, 0);

		glCompileShader(shaderObject);
		delete[] data;

		// check for errors
		GLint status = 0;
		glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &status);

		// found one
		if (!status)
		{
			char buffer[4096];
			glGetShaderInfoLog(shaderObject, 4096, NULL, buffer);

			fprintf(stderr, "Error(ShaderLoadNCompile.cpp) %s: %s\n", shaderFileName, buffer);

			assert(false);
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool ShaderObject::CreateVertFragShader(const char* vertShaderName, const char* fragShaderName)
{
	//64 is an arbitrary guess at capacity
	String name(64);

	name = "Shaders/";
	name += fragShaderName;
	name += ".fs.glsl";
	
	LoadNCompile(fragShader, name, GL_FRAGMENT_SHADER);

	name = "Shaders/";
	name += vertShaderName;
	name += ".vs.glsl";

	LoadNCompile(vertShader, name, GL_VERTEX_SHADER);

	// Creates an empty program object
	programObject = glCreateProgram();

	//Attaches a shader object to a program object
	glAttachShader(programObject, vertShader);
	glAttachShader(programObject, fragShader);

	// Links a program object
	glLinkProgram(programObject);

	return true;
}
