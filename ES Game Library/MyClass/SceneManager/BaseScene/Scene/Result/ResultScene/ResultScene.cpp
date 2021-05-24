#include "ResultScene.h"

ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {

}

bool ResultScene::Initialize() {
	result = GraphicsDevice.CreateSpriteFromFile(_T("Result/result.png"));
	return true;
}

int ResultScene::Update() {
	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Space))
		return Scene::NEXT;
	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3_Zero);
}