#include"SceneManager.h"
#include"BaseScene/Scene/Tittle/TitleManager.h"
SceneManager::SceneManager()
{
	_child_scene.reset();
}

SceneManager::~SceneManager()
{
}

bool SceneManager::Initialize()
{
	_child_scene.reset(new TitleManager);
	_child_scene->Initialize();
	return 0;
}

int SceneManager::Update()
{
	if (_child_scene->Update() == _child_scene->NEXT)
	{
		_child_scene.reset();
	}
	return 0;
}

void SceneManager::Draw()
{
	GraphicsDevice.BeginScene();
	_child_scene->Draw3D();

	SpriteBatch.Begin();

	_child_scene->Draw2D();

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}