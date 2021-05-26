#include "ResultScene.h"
#include "../../../../SceneManager.h"

ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {

}

bool ResultScene::Initialize() {
	font     = GraphicsDevice.CreateSpriteFont(_T("@UD デジタル 教科書体 N-B"), 120);
	result   = GraphicsDevice.CreateSpriteFromFile(_T("Result/result_background.png"));
	record   = GraphicsDevice.CreateSpriteFromFile(_T("Result/result.png"));
	dramroll = SoundDevice.CreateSoundFromFile(_T("Audio/SoundEffect/dramroll.wav"));
	dramroll->Play();

	bgm = SoundDevice.CreateMusicFromFile(_T("Audio/Bgm/result.wav"));
	//bgm->Play();

	InputDevice.CreateGamePad(1);
	return true;
}

int ResultScene::Update() {

	if (count < MAX_COUNT)
		count++;
	else
		appear_flag = true;


	KeyboardBuffer key = Keyboard->GetBuffer();
	GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space) || pad.IsPressed(GamePad_Button4))
		return Scene::NEXT;

	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3(0,0,2));
	SpriteBatch.Draw(*record, Vector3(130,100,1));
	if (appear_flag) {
		SpriteBatch.DrawString(font, Vector2(530, 260), Color_Black, _T("%d"), SceneManager::Instance().GetDeathEnemy());
		SpriteBatch.DrawString(font, Vector2(500, 460), Color_Black, _T("%d"), SceneManager::Instance().GetCombo());
	}
}