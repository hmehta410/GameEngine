#include "ModelMan.h"
#include "File\File.h"
#include "Array\Array.h"
#include "String\String.h"
#include "List\Link.h"
#include <assert.h>
#include <memory>

//used to contain the model and the identifying trait (i.e. name, dimensions)
struct ModelMan::ModelNode : public SLink
{
	Model model;
	String name;
};

struct ModelMan::GridNode : public SLink
{
	Model model;
	int x, y;
};

ModelMan::ModelMan()
{
}

ModelMan::~ModelMan()
{
	this->namedMeshes.DeleteList();
	this->gridNodes.DeleteList();
}

namespace
{
	struct Vertex
	{
		static const int kMaxBoneInfluences = 4;
		float x, y, z; //position
		float u, v;	//uv texture coordinates
		float nx, ny, nz; //normals
		float weights[kMaxBoneInfluences]; //the weights of 4 bones
		unsigned int boneIndex[kMaxBoneInfluences]; //the corresponding index of each bone
	};

	//a helpful struct for casting raw triangle data
	struct Tri_index
	{
		unsigned int v0;
		unsigned int v1;
		unsigned int v2;
	};

	//the mesh header was defined early on under the assumption of a larger scope
	// of serializing scenes rather than separately packaged meshes
	struct MeshHeader
	{
		static const int kObjectNameSize = 32;
		char name[kObjectNameSize];
		int numVerts;
		int numTris;

		//the id and parent id refer to meshes that are packaged together in one file
		// and may not be unique across the program
		int id;
		int parentId;
		int numTextures;

		//bounding sphere
		float x, y, z;
		float radius;
	};

	//returns a unique_ptr because the buffer is dynamically allocated and 
	//does not have an owner
	std::unique_ptr<char[]> ReadFile(const char* filename)
	{
		File file(filename, FileMode::READ);
		FileError error = file.GetError();
		assert(FileError::NONE == error);

		int fileSize = file.GetSize();

		std::unique_ptr<char[]> buffer(new char[fileSize]);
		file.Read(buffer.get(), fileSize);

		return buffer;
	}

	void AddMesh(const char* filename, Model& outModel)
	{
		//read the file into a buffer
		auto buffer = ReadFile(filename);

		//cast the buffer into header, mesh data, triList, and texture names
		MeshHeader* mesh = (MeshHeader*)buffer.get();
		Vertex* meshData = (Vertex*)(buffer.get() + sizeof(MeshHeader));
		Tri_index* triList = (Tri_index*)(buffer.get() + sizeof(MeshHeader) + sizeof(Vertex)*mesh->numVerts);
		char * texNameBuffer = (char*)(buffer.get() + sizeof(MeshHeader) + sizeof(Vertex)*mesh->numVerts + sizeof(Tri_index)*mesh->numTris);
		
		texNameBuffer; //is unused

		//set the output models values from the header
		outModel.x = mesh->x;
		outModel.y = mesh->y;
		outModel.z = mesh->z;
		outModel.radius = mesh->radius;

		outModel.numVerts = mesh->numVerts;
		outModel.numTris = mesh->numTris;


		//use the mesh data to create an OpenGL-side mesh
		// Create a VAO
		glGenVertexArrays(1, &outModel.vao);
		assert(outModel.vao != 0);
		glBindVertexArray(outModel.vao);

		// Create a VBO
		glGenBuffers(2, &outModel.vbo[0]);
		assert(outModel.vbo[0] != 0);

		glBindBuffer(GL_ARRAY_BUFFER, outModel.vbo[0]);

		// load the data to the GPU
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * outModel.numVerts, meshData, GL_STATIC_DRAW);

		// Define an array of generic vertex attribute data
		// Vert data is location: 0  (used in vertex shader)
		// todo make a table or enum
		void *offsetVert = (void *)((unsigned int)&meshData[0].x - (unsigned int)meshData);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetVert);
		glEnableVertexAttribArray(0);

		// Texture data is location: 1  (used in vertex shader)
		void *offsetTex = (void *)((unsigned int)&meshData[0].u - (unsigned int)meshData);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetTex);
		glEnableVertexAttribArray(1);

		// normals data in location 2 (used in vertex shader)
		void *offsetNorm = (void *)((unsigned int)&meshData[0].nx - (unsigned int)meshData);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetNorm);
		glEnableVertexAttribArray(2);

		// weight data in location 3 (used in vertex shader)
		void *offsetWeight = (void*)((char*)meshData[0].weights - (char*)meshData);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetWeight);
		glEnableVertexAttribArray(3);

		// bone data in location 4 (used in vertex shader)
		void *offsetIndex = (void*)((char*)meshData[0].boneIndex - (char*)meshData);

		glVertexAttribIPointer(4, 4, GL_INT, sizeof(Vertex), offsetIndex);
		glEnableVertexAttribArray(4);

		// Load the index data: ---------------------------------------------------------

		/* Bind our 2nd VBO as being the active buffer and storing index ) */
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, outModel.vbo[1]);

		/* Copy the index data to our buffer */
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Tri_index)* outModel.numTris, triList, GL_STATIC_DRAW);
	}

	//a helpful struct for creating a 2D grid
	struct GridPoint
	{
		float x;
		float z;
	};

	//generates the xz coordiantes of each vertex in the grid
	Array<GridPoint> GenerateGridPoints(int width, int height)
	{
		int numVerts = 2 * (width + height + 2);
		Array<GridPoint> gridPoints(numVerts);

		int count = 0;

		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;
		for (int i = 0; i <= width; i++)
		{
			gridPoints[count].x = i - halfWidth;
			gridPoints[count].z = -halfHeight;
			count++;

			gridPoints[count].x = i - halfWidth;
			gridPoints[count].z = halfHeight;
			count++;
		}

		for (int j = 0; j <= height; j++)
		{
			gridPoints[count].x = -halfWidth;
			gridPoints[count].z = j - halfHeight;
			count++;

			gridPoints[count].x = halfWidth;
			gridPoints[count].z = j - halfHeight;
			count++;
		}

		return gridPoints;
	}

	//creates an opengl side mesh
	void GenerateGLGrid(int width, int height, Model& outModel)
	{
		Array<GridPoint> gridPoints = GenerateGridPoints(width, height);

		outModel.x = 0.0f;
		outModel.y = 0.0f;
		outModel.z = 0.0f;
		outModel.radius = 0.0f;

		outModel.numVerts = gridPoints.Size();
		outModel.numTris = 0;

		glGenVertexArrays(1, &outModel.vao);
		assert(outModel.vao != 0);
		glBindVertexArray(outModel.vao);

		glGenBuffers(1, &outModel.vbo[0]);
		assert(outModel.vbo[0] != 0);
		glBindBuffer(GL_ARRAY_BUFFER, outModel.vbo[0]);

		glBufferData(GL_ARRAY_BUFFER, sizeof(GridPoint) * outModel.numVerts, gridPoints.begin(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GridPoint), 0);
		glEnableVertexAttribArray(0);
	}
}

Model* ModelMan::FindMesh(const char* fileName)
{
	ModelMan* man = GetInstance();
	LinkedIterator it = man->namedMeshes.GetIterator();

	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		ModelNode* node = (ModelNode*)link;
		if (node->name == fileName)
		{
			return &node->model;
		}
	}

	return nullptr;
}

Model* ModelMan::FindGrid(int widthDivisions, int heightDivisions)
{
	ModelMan* man = GetInstance();
	LinkedIterator it = man->gridNodes.GetIterator();

	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		GridNode* node = (GridNode*)link;
		if (node->x == widthDivisions && node->y == heightDivisions)
		{
			return &node->model;
		}
	}

	return nullptr;
}

Model* ModelMan::LoadMesh(const char* fileName)
{
	//check to see if we have previously loaded the mesh
	ModelMan* man = GetInstance();
	Model* outputModel = man->FindMesh(fileName);

	//if (we didn't load the mesh before) 
	if (outputModel == nullptr)
	{
		ModelNode* node = new ModelNode();
		AddMesh(fileName, node->model);
		node->name = fileName;

		man->namedMeshes.PushFront(node);
		outputModel = &node->model;
	}
	return outputModel;
}

Model* ModelMan::LoadGrid(int widthDivisions, int heightDivisions)
{
	//check to see if we have previously loaded a grid this size
	ModelMan* man = GetInstance();
	Model* outputModel = man->FindGrid(widthDivisions, heightDivisions);

	//if (we didn't load the grid before)
	if (outputModel == nullptr)
	{
		GridNode* node = new GridNode();

		node->x = widthDivisions;
		node->y = heightDivisions;
		GenerateGLGrid(widthDivisions, heightDivisions, node->model);

		man->gridNodes.PushFront(node);
		outputModel = &node->model;
	}
	return outputModel;
}

ModelMan* ModelMan::GetInstance()
{
	static ModelMan man;
	return &man;
}
