#include"TitleScene.h"
#include"../../../../../ResouceManager/ResouceManager.h"
TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
}

bool TitleScene::Initialize()
{
	//font = GraphicsDevice.CreateSpriteFont(_T("UD �f�W�^�� ���ȏ��� N-B"), );
	bg    = ResouceManager::Instance().LordSpriteFile(_T("Title/�s�h�s�k�d_background.png"));
	logo  = ResouceManager::Instance().LordSpriteFile(_T("Title/�s�h�s�k�d_��������.png"));
	title = ResouceManager::Instance().LordMusicFile(_T("Audio/Bgm/title.wav"));
	title->Play();
	SceneManager::Instance().SetCombo(0);	
	SceneManager::Instance().SetDeathEnemy(0);
	InputDevice.CreateGamePad(1);
	return true;
}

int TitleScene::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space) || pad.IsPressed(GamePad_Button4))
	{
		title->Stop();
		return Scene::NEXT;
	}

	return Scene::NOW;
}

void TitleScene::Draw2D()
{
	SpriteBatch.Draw(*bg, Vector3_Zero);
	SpriteBatch.Draw(*logo, Vector3(270,100,-10000));
}