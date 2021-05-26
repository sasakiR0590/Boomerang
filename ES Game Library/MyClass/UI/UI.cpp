#include "UI.h"
#include"../SceneManager/SceneManager.h"
UI::UI() {

}

UI::~UI() {

}

bool UI::Initialize() {
	time_font      = GraphicsDevice.CreateSpriteFont(_T("@UD デジタル 教科書体 N-B"), 80);
	time_over_font = GraphicsDevice.CreateSpriteFont(_T("@UD デジタル 教科書体 N-B"), 50);
	start_finish   = GraphicsDevice.CreateSpriteFromFile(_T("ui/START、ＦＩＮＩＳＨ.png"));
	combo          = GraphicsDevice.CreateSpriteFromFile(_T("ui/ＣＯＭＢＯ.png"));
	time           = GraphicsDevice.CreateSpriteFromFile(_T("ui/TIME_2.png"));
	return true;
}

int UI::Update() {

	SpriteAlpha();

	if (SceneFlag())
		return 1;

#ifdef _DEBUG
	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Z))
		test_flag = true;

	if (test_flag)
		StringAlpha();
#endif

	return 0;
}

bool UI::SceneFlag() {
	//スタートしていて時間が 制限時間 より大きい場合　または 制限時間で終了時処理が終わった時
	auto flag = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over ||
			    TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA&& count >= MAX_COUNT;

	if (flag)return true;

	return false;
}

int  UI::SpriteAlpha() {
	//ゲーム開始前処理 または ゲーム終了時処理
	auto start_sprite_alpha = !TimeManager::Instance().StartFlag()                && sprite_alpha < MAX_ALPHA && count < MAX_COUNT ||
		                       TimeManager::Instance().GetTimeLeft() < time_over  && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	//ゲーム中
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

int UI::StringAlpha() {
	if (test_flag) {
		if (string_alpha < MAX_ALPHA && frame < MAX_COUNT) {
			string_alpha += ALPHA_NUM;
			frame++;
		}
		else
			test_flag = false;
	}
	else {
		string_alpha = MIN_ALPHA;
		frame = MIN_FRAME;
	}
	return string_alpha;
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
	//start
	if(!TimeManager::Instance().StartFlag())
	SpriteBatch.Draw(*start_finish, Vector3(450,320,1),RectWH(0,0,300,64),Color(255,255, 255, SpriteAlpha()));

	SpriteBatch.Draw(*time, Vector3(0,0, 1));
	SpriteBatch.Draw(*combo, Vector3(250, 100, 1));
	SpriteBatch.DrawString(time_font, Vector2(130, 97), Color_White, _T("%d"), SceneManager::Instance().GetCombo());

#ifdef _DEBUG
	if (test_flag) {
		SpriteBatch.DrawString(time_over_font, Vector2(130, 100), Color(255,255, 255, StringAlpha()), _T("敵撃破ボーナス"));
		SpriteBatch.DrawString(time_over_font, Vector2(200, 150), Color(255,255, 255, StringAlpha()), _T("＋○秒"));
	}
#endif
		if (TimeManager::Instance().GetTimeLeft() > time_over)
			SpriteBatch.DrawString(time_font, Vector2(240, 12), TimeColor(), _T("%.3f"), TimeManager::Instance().GetTimeLeft());
		else {
			SpriteBatch.DrawString(time_over_font, Vector2(250, 25), Color_Red, _T("TIME OVER"));
			//finish
			SpriteBatch.Draw(*start_finish, Vector3(450, 320, 1), RectWH(400, 0, 750, 64), Color(255, 255, 255, SpriteAlpha()));
		}
	
}