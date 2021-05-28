#include "ResultScene.h"
#include "../../../../SceneManager.h"
#include"../../../../../ResouceManager/ResouceManager.h"
#include <fstream>
ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {
}

bool ResultScene::Initialize() {

	SaveScore();
	font     = GraphicsDevice.CreateSpriteFont(_T("UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì N-B"), 120);
	result   = GraphicsDevice.CreateSpriteFromFile(_T("Result/result_background.png"));
	record   = GraphicsDevice.CreateSpriteFromFile(_T("Result/result.png"));
	dramroll = SoundDevice.CreateSoundFromFile(_T("Audio/SoundEffect/dramroll.wav"));
	dramroll->Play();

	bgm = ResouceManager::Instance().LordMusicFile(_T("Audio/Bgm/result.wav"));
	bgm->Play();

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
	{	
		bgm->Stop();
		return Scene::NEXT;
	}

	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3(0,0,2));
	SpriteBatch.Draw(*record, Vector3(130,100,1));
	if (appear_flag) {
		SpriteBatch.DrawString(font, Vector2(530, 260), Color_Black, _T("%d"), SceneManager::Instance().GetDeathEnemy());
		SpriteBatch.DrawString(font, Vector2(270, 460), Color_Black, _T("Å‘å %d"), SceneManager::Instance().MaximumCombo());
	}
}

void ResultScene::SaveScore()
{
	std::ifstream pos_time_infile("Score/Score.txt");

	float score[2];
	char dummy;
	pos_time_infile >> score[0] >> dummy >> score[1];
	if (SceneManager::Instance().GetDeathEnemy() > score[0])
		score[0] = SceneManager::Instance().GetDeathEnemy();
	if (SceneManager::Instance().MaximumCombo() > score[1])
		score[1] = SceneManager::Instance().MaximumCombo();
	std::ofstream outputfile("Score/Score.txt");
	outputfile << score[0] << ',' << score[1];
	outputfile.close();
}
