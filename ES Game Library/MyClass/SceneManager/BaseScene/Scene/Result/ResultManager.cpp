#include"ResultManager.h"
#include"../../../../Data/WordsTable.h"
ResultManager::ResultManager()
{
	_next_scene = SceneNumber::TITLE;
}

ResultManager::~ResultManager()
{
}

bool ResultManager::Initialize()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

int ResultManager::Update()
{
	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Space))
		return Scene::NEXT;
	return Scene::NOW;
}

void ResultManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}