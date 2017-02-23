#include "ShaderMan.h"
#include "List\LinkedIterator.h"
#include "Assert.h"
#include <string.h>

ShaderMan::ShaderMan()
{
}

ShaderMan::~ShaderMan()
{
	this->shaders.DeleteList();
}

ShaderObject* ShaderMan::FindShader(const char* shaderName)
{
	DList& shaders = ShaderMan::getInstance()->shaders;
	LinkedIterator it = shaders.GetIterator();

	for (Link* node = it.First(); !it.IsDone(); node = it.Next())
	{
		if (strcmp(((ShaderObject*)node)->GetName(), shaderName) == 0)
		{
			return (ShaderObject*)node;
		}
	}

	return nullptr;
}

ShaderObject* ShaderMan::LoadShader(const char* shaderName)
{
	ShaderObject* shader = FindShader(shaderName);

	if (shader == nullptr)
	{
		shader = new ShaderObject(shaderName);
		ShaderMan::getInstance()->shaders.PushFront(shader);
	}
	return shader;
}

ShaderMan* ShaderMan::getInstance()
{
	static ShaderMan man;
	return &man;
}