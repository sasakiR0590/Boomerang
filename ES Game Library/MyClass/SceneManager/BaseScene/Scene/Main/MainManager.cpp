#include"MainManager.h"
#include"MainGame/MainGame.h"
MainManager::MainManager()
{
}

MainManager::~MainManager()
{
}

bool MainManager::Initialize()
{
	_child_scene.push_back(std::make_unique<MainGame>());
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

void MainManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}
void MainManager::Draw3D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw3D();
	}
}