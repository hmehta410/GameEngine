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
	auto& shaders = ShaderMan::getInstance()->shaders;
	auto it = shaders.GetIterator();

	for (ShaderObject* node = it.First(); !it.IsDone(); node = it.Next())
	{
		if (strcmp(node->GetName(), shaderName) == 0)
		{
			return node;
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