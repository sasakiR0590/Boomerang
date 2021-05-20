#pragma once
#include"../../../ESGLib.h"

class BaseScene
{
public:
	BaseScene() {};
	~BaseScene();

	virtual bool Initialize() = 0;
	int BeginScene(std::list<BaseScene*> scene);
	virtual int Update();
	virtual void Draw2D() {};
	virtual void Draw3D() {};
	string GetNextScene() { return _next_scene;}
	enum Scene { NOW, NEXT };
protected:
	std::list<BaseScene*> _child_scene;
	string _next_scene;
private:
};