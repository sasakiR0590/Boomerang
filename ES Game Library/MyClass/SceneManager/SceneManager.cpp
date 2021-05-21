#include"SceneManager.h"
#include"BaseScene/Scene/Tittle/TitleManager.h"
#include"BaseScene/Scene/Main/MainManager.h"
#include"BaseScene/Scene/Result/ResultManager.h"
#include"../Data/WordsTable.h"

SceneManager::SceneManager()
{
	_scene = nullptr;
}

SceneManager::~SceneManager()
{
}
void SceneManager::ChangeScene(string scene)
{
	_scene.reset();

	if (scene == SceneNumber::TITLE)		_scene = std::make_unique<TitleManager>();
	else if (scene == SceneNumber::MAIN)	_scene = std::make_unique<MainManager>();
	else if (scene == SceneNumber::RESULT)	_scene = std::make_unique<ResultManager>();

	assert(_scene && "ŠY“–scene‚È‚µ");
	_scene->Initialize();
}
bool SceneManager::Initialize(string scene)
{
	ChangeScene(scene);
	return 0;
}

int SceneManager::Update()
{
	if (_scene->Update() == _scene->NEXT)
	{
		ChangeScene(_scene->GetNextScene());
	}
	return 0;
}

void SceneManager::Draw()
{
	GraphicsDevice.Clear(Color_CornflowerBlue);
	GraphicsDevice.BeginScene();

	_scene->Draw3D();

	SpriteBatch.Begin();

	_scene->Draw2D();

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
