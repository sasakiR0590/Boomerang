#include"TitleManager.h"
#include"TitleScene/TitleScene.h"
TitleManager::TitleManager()
{
	_child_scene.clear();
}

TitleManager::~TitleManager()
{
}

bool TitleManager::Initialize()
{
	BaseScene* scene = new TitleScene;
	_child_scene.push_back(scene);
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

void TitleManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}