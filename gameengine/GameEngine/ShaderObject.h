#ifndef SHADER_OBJECT_H
#define SHADER_OBJECT_H

#include "GL\glew.h"
#include "List\Link.h"
#include "String\String.h"

/*
Represents a shader program on the openGL side. It must be instantiated through
ShaderMan.
*/
class ShaderObject : public DLink
{
public:
	~ShaderObject();

	void UseProgram() const;
	GLuint GetUniformLocation(const char * uniformName) const;
	GLuint GetUniformBlockIndex(const char * blockName) const;
	GLuint GetProgramObject() const;
	const String& GetName() const;

private:
	//private constructor means it can only be created by friend ShaderMan
	ShaderObject(const char* shaderBaseFileName);
	bool CreateVertFragShader(const char* vertShaderName, const char* fragShaderName);

	GLuint	programObject;
	GLuint fragShader;
	GLuint vertShader;
	String shaderName;

	friend class ShaderMan;
};

#endif