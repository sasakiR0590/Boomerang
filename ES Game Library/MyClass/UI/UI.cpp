#include "UI.h"
#include"../SceneManager/SceneManager.h"
#include "../Data/WordsTable.h"
#include "../ResouceManager/ResouceManager.h"
UI::UI() {

}

UI::~UI() {

}

bool UI::Initialize() {
	start_finish   = ResouceManager::Instance().LordSpriteFile(_T("ui/START�A�e�h�m�h�r�g.png"));
	combo          = ResouceManager::Instance().LordSpriteFile(_T("ui/�b�n�l�a�n.png"));
	time           = ResouceManager::Instance().LordSpriteFile(_T("ui/TIME_2.png"));
	start          = ResouceManager::Instance().LordSoundFile(_T("Audio/SoundEffect/Item/powerup.wav"));
	end            = ResouceManager::Instance().LordSoundFile(_T("Audio/SoundEffect/whistle.wav"));
	time_over_font = GraphicsDevice.CreateSpriteFont(_T("UD �f�W�^�� ���ȏ��� N-B"), 50);
	time_font      = GraphicsDevice.CreateSpriteFont(_T("UD �f�W�^�� ���ȏ��� N-B"), 80);

	start->SetVolume(0.95f);
	end->SetVolume(0.8f);
	return true;
}

int UI::Update() {
	SpriteAlpha();
	Sound();

	if (SceneFlag()) {
		return 1;
	}

	return 0;
}

/**
 * @fn     �Q�[���J�n�ƏI������SE
 * @brief  �Q�[���J�n�E�I������sound_state��auto�^�̕ϐ�������SE��炷
 * @return �Ȃ�
 */

void UI::Sound() {
	//!�Q�[���J�nSE
	auto start_se = !TimeManager::Instance().StartFlag();
	//!�Q�[���I��SE
	auto end_se   = TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	if (start_se && sound_state == SE_START) {
		start->Play();
		sound_state = SE_END;
	}
	if (end_se && sound_state == SE_END) {
		end->Play();
		sound_state = NUM;
	}
}

/**
 * @fn �@  �V�[���J�ڗp�̃t���O
 * @brief  auto�^�̕ϐ��̏����������ɃQ�[���J�n�E�I�����ɃV�[���J�ڗp�t���O��Ԃ�
 * @return �V�[���J�ڗp�t���O
 */

bool UI::SceneFlag() {
	//!�X�^�[�g���Ă��Ď��Ԃ� �������� ���傫���ꍇ�@�܂��� �������ԂŏI�����������I�������
	auto flag = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over ||
			    TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA&& count >= MAX_COUNT;

	if (flag)return true;

	return false;
}

/**
 * @fn �@  �摜�̓_��
 * @brief  auto�^�̕ϐ��̏����������ɃQ�[���J�n�E�I�����ɉ摜��_�ł�����
 * @return �摜��alpha�l
 */

int  UI::SpriteAlpha() {
	//!�Q�[���J�n�O���� �܂��� �Q�[���I��������
	auto start_sprite_alpha = !TimeManager::Instance().StartFlag()                && sprite_alpha < MAX_ALPHA && count < MAX_COUNT ||
		                       TimeManager::Instance().GetTimeLeft() < time_over  && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	//!�Q�[�����̏ꍇ
	auto between_game       = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over;

	int  over_sprite_alpha  = sprite_alpha >= MAX_ALPHA;

	if (start_sprite_alpha)
		sprite_alpha += ALPHA_NUM;
	else if (over_sprite_alpha) {
		sprite_alpha = MIN_ALPHA;
		count++;
	}
	else if (between_game) {
		count = MIN_COUNT;
		sprite_alpha = MIN_ALPHA;
	}

	return sprite_alpha;
}

Color UI::TimeColor() {
  switch ((int)TimeManager::Instance().GetTimeLeft()) {
    case START:
    	color = Color_White;
    	break;
    case HARF:
    	color = Color_Orange;
    	break;
    case END:
    	color = Color_Red;
    	break;
  }
	return color;
}

void UI::Draw() {
	//!�Q�[���J�n
	if(!TimeManager::Instance().StartFlag())
	SpriteBatch.Draw(*start_finish, Vector3(450,320,1),RectWH(0,0,300,64),Color(255,255, 255, SpriteAlpha()));

	SpriteBatch.Draw(*time, Vector3(0,0, 1));
	SpriteBatch.Draw(*combo, Vector3(250, 100, 1));
	SpriteBatch.DrawString(time_font, Vector2(130, 97), Color_White, _T("%d"), SceneManager::Instance().GetCombo());

		if (TimeManager::Instance().GetTimeLeft() > time_over)
			SpriteBatch.DrawString(time_font, Vector2(240, 12), TimeColor(), _T("%.3f"), TimeManager::Instance().GetTimeLeft());
		else {
			SpriteBatch.DrawString(time_over_font, Vector2(250, 25), Color_Red, _T("TIME OVER"));
			//!�Q�[���I��
			SpriteBatch.Draw(*start_finish, Vector3(450, 320, 1), RectWH(400, 0, 750, 64), Color(255, 255, 255, SpriteAlpha()));
		}
	
}