#include"BaseScene.h"
BaseScene::~BaseScene()
{
	for (auto& it = _child_scene.rbegin(); it != _child_scene.rend(); ++it)
	{
		delete (*it);
	}
	_child_scene.clear();
}
int BaseScene::BeginScene(std::list<BaseScene*> scene)
{
	int next = Scene::NEXT;
	for (auto&& childscene : scene)
	{
		if (childscene->Update() == childscene->NOW)
		{
			next = Scene::NOW;
			break;
		}
	}
	return next;
}
int BaseScene::Update()
{
	return BeginScene(_child_scene);
}