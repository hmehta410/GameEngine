#ifndef SHADER_MAN_H
#define SHADER_MAN_H

#include "ShaderObject.h"
#include "List\DList.h"

/*
Creates and Manages ShaderObjects. 
*/
class ShaderMan
{
public:
	static ShaderObject* LoadShader(const char* shaderName);
	static ShaderObject* FindShader(const char* shaderName);

private:
	ShaderMan();
	~ShaderMan();
	static ShaderMan* getInstance();

	DList shaders;
};

#endif