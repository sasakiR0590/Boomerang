#include "ResultScene.h"

ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {

}

bool ResultScene::Initialize() {
	//font = GraphicsDevice.CreateSpriteFont(_T("@UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì N-B"), );

	result = GraphicsDevice.CreateSpriteFromFile(_T("Result/result_background.png"));
	record = GraphicsDevice.CreateSpriteFromFile(_T("Result/result.png"));
	return true;
}

int ResultScene::Update() {
	KeyboardBuffer key = Keyboard->GetBuffer();
	GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space) || pad.IsReleased(GamePad_Button4))
		return Scene::NEXT;
	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3_Zero);
	SpriteBatch.Draw(*record, Vector3(130,100,-1));
}