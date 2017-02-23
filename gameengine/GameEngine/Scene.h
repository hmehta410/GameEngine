#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	virtual ~Scene() {}
	virtual void Update(float time) = 0;
	virtual void Draw(float) {};
	virtual void Clean() {};
};

#endif