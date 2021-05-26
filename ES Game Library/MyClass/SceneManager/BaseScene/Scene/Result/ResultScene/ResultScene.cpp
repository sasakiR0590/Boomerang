#include "ResultScene.h"
#include "../../../../SceneManager.h"

ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {

}

bool ResultScene::Initialize() {
	font = GraphicsDevice.CreateSpriteFont(_T("@UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì N-B"), 120);

	result = GraphicsDevice.CreateSpriteFromFile(_T("Result/result_background.png"));
	record = GraphicsDevice.CreateSpriteFromFile(_T("Result/result.png"));
	return true;
}

int ResultScene::Update() {
	KeyboardBuffer key = Keyboard->GetBuffer();
//	GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space))
		return Scene::NEXT;
	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3(0,0,2));
	SpriteBatch.Draw(*record, Vector3(130,100,1));
	SpriteBatch.DrawString(font, Vector2(530, 260), Color_Black, _T("%d"), SceneManager::Instance().GetDeathEnemy());
	SpriteBatch.DrawString(font, Vector2(500, 460), Color_Black, _T("%d"),SceneManager::Instance().GetCombo());
}