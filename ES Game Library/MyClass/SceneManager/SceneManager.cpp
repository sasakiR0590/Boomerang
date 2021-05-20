#include"SceneManager.h"
#include"BaseScene/Scene/Tittle/TitleManager.h"
#include"BaseScene/Scene/Main/MainManager.h"
#include"../Data/WordsTable.h"
SceneManager::SceneManager()
{
	_child_scene.reset();
}

SceneManager::~SceneManager()
{
}
void SceneManager::ChangeScene(string scene)
{
	_child_scene.reset();

	if (scene == SceneNumber::TITLE)_child_scene.reset(new TitleManager);
	if (scene == SceneNumber::MAIN)_child_scene.reset(new MainManager);

	_child_scene->Initialize();
}
bool SceneManager::Initialize(string scene)
{
	ChangeScene(scene);
	return 0;
}

int SceneManager::Update()
{
	if (_child_scene->Update() == _child_scene->NEXT)
	{
		ChangeScene(_child_scene->GetNextScene());
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
