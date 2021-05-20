#include"TitleManager.h"
#include"TitleScene/TitleScene.h"
TitleManager::TitleManager()
{
}

TitleManager::~TitleManager()
{
}

bool TitleManager::Initialize()
{
	unique_ptr<BaseScene> scene = make_unique<TitleScene>();
	_child_scene.push_back(scene);
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

int TitleManager::Update()
{
	for (auto&& childscene : _child_scene)
	{
		if (childscene->Update() == Scene::NOW)
			break;
	}
	return 0;
}

void TitleManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}