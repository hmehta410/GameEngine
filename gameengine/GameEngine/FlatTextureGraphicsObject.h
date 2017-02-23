#ifndef GRAPHICS_OBJECT_FLAT_TEXTURE_H
#define GRAPHICS_OBJECT_FLAT_TEXTURE_H

#include "GraphicsObject.h"
#include "TextureManager.h"

//This draws a mesh with a flat texture. There is no lighting or base color 
//associated with this graphicsObject.
class FlatTextureGraphicsObject :public GraphicsObject
{
public:
	FlatTextureGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, Texture* node);

	//move is for textureID
	FlatTextureGraphicsObject(FlatTextureGraphicsObject&& other);
	FlatTextureGraphicsObject& operator=(FlatTextureGraphicsObject&& other);

	//GrahpicsObject contract
	virtual void SetState() override;
	virtual void SetGPUData() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	GLuint textureID;
	GLuint projMatrixIndex;
	GLuint viewMatrixIndex;
	GLuint worldMatrixIndex;
};
#endif