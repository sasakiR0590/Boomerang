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
	return 0;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3_Zero);
}