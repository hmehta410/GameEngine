#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	virtual ~Scene() {}
	virtual void Update() = 0;
	virtual void Draw() {};
	virtual void Clean() {};
};

#endif