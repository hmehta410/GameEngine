#pragma once

#include "Model.h"
#include "List\SList.h"

class ModelMan
{
public:
	~ModelMan();
	static Model* LoadMesh(const char* fileName);
	static Model* LoadGrid(int widthDivisions, int heightDivisions);

	static Model* FindMesh(const char* fileName);
	static Model* FindGrid(int widthDivisions, int heightDivisions);

private:
	struct ModelNode;
	struct GridNode;

	ModelMan();
	static ModelMan* GetInstance();

	SList namedMeshes; //type MeshNode
	SList gridNodes; //type GridNode;
};
