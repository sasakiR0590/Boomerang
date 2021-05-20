#include"TitleScene.h"

TitleScene::TitleScene()
{
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
	return Scene::NEXT;
}

void TitleScene::Draw2D()
{
	SpriteBatch.Draw(*bg, Vector3_Zero);
}