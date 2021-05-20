#pragma once
#include"../../../ESGLib.h"

class BaseScene
{
public:
	BaseScene() {};
	~BaseScene() {};

	virtual bool Initialize() = 0;
	//int BeginScene(std::list<std::unique_ptr<BaseScene>> scene) = 0;
	virtual int Update() = 0;
	virtual void Draw2D() {};
	virtual void Draw3D() {};
	enum Scene { NOW, NEXT };
protected:
	std::list<BaseScene*> _child_scene;
private:
};