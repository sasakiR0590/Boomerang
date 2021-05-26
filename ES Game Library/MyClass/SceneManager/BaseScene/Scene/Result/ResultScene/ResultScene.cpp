#include "ResultScene.h"

ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {

}

bool ResultScene::Initialize() {
	//font = GraphicsDevice.CreateSpriteFont(_T("@UD デジタル 教科書体 N-B"), );

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
	SpriteBatch.Draw(*result, Vector3_Zero);
	SpriteBatch.Draw(*record, Vector3(130,100,-1));
}