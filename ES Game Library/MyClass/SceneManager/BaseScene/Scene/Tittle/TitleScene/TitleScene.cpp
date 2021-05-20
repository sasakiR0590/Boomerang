#include"TitleScene.h"

TitleScene::TitleScene()
{
	_child_scene.clear();
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Initialize()
{
	bg = GraphicsDevice.CreateSpriteFromFile(_T("Title/bg.png"));
	return true;
}

int TitleScene::Update()
{
	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Space))
		return Scene::NEXT;
	return Scene::NOW;
}

void TitleScene::Draw2D()
{
	SpriteBatch.Draw(*bg, Vector3_Zero);
}