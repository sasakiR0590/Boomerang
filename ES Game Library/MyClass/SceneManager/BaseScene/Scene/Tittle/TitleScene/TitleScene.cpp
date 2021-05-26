#include"TitleScene.h"

TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
}

bool TitleScene::Initialize()
{
	//font = GraphicsDevice.CreateSpriteFont(_T("@UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì N-B"), );
	bg = GraphicsDevice.CreateSpriteFromFile(_T("Title/‚s‚h‚s‚k‚d_background.png"));

	SceneManager::Instance().SetCombo(0);	
	SceneManager::Instance().SetDeathEnemy(0);
	return true;
}

int TitleScene::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	//GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space))
		return Scene::NEXT;
	return Scene::NOW;
}

void TitleScene::Draw2D()
{
	SpriteBatch.Draw(*bg, Vector3_Zero);
}