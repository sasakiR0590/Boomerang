#pragma once
#include"../../../ESGLib.h"

class BaseScene
{
public:
	BaseScene() {};
	~BaseScene() {};

	virtual bool Initialize() = 0;
	virtual int Update() = 0;
	virtual void Draw2D() {};
	virtual void Draw3D() {};
protected:
	std::list<std::unique_ptr<BaseScene>> _child_scene;
	enum Scene{NOW,NEXT};
private:
};