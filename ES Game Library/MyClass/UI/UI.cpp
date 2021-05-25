#include "UI.h"

UI::UI() {

}

UI::~UI() {

}

bool UI::Initialize() {
	time_font      = GraphicsDevice.CreateSpriteFont(_T("������ Demibold"), 80);
	time_over_font = GraphicsDevice.CreateSpriteFont(_T("������ Demibold"), 50);
	ui             = GraphicsDevice.CreateSpriteFromFile(_T("ui/START�A�e�h�m�h�r�g.png"));
	time           = GraphicsDevice.CreateSpriteFromFile(_T("ui/TIME_2.png"));
	return true;
}

int UI::Update() {
	now_time      = TimeManager::Instance().GetTimeLeft();
	SpriteAlpha();
#ifdef _DEBUG
	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Z))
		test_flag = true;

	if (test_flag)
		StringAlpha();
#endif

	if (clear_flag)
		return 1;

	return 0;
}

int  UI::SpriteAlpha() {
	auto start_sprite_alpha = !TimeManager::Instance().StartFlag() && sprite_alpha < MAX_ALPHA && count < MAX_COUNT ||
                               now_time < time_over && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	auto between_game       = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over;

	int  over_sprite_alpha  = sprite_alpha >= MAX_ALPHA;

	auto game_clear         = now_time < time_over&& sprite_alpha < MAX_ALPHA&& count >= MAX_COUNT;

	if (start_sprite_alpha)
		sprite_alpha += ALPHA_NUM;
	else if (over_sprite_alpha) {
		sprite_alpha = MIN_ALPHA;
		count++;
	}
	else if (between_game)
		count = MIN_COUNT;


	if (game_clear)
		clear_flag = true;

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
  switch ((int)now_time) {
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
	SpriteBatch.Draw(*ui, Vector3(450,320,1),RectWH(0,0,300,64),Color(255,255, 255, SpriteAlpha()));

	//	SpriteBatch.DrawString(time_font, Vector2(500, 15), Color_White, _T("%d"), combo_counter);

	SpriteBatch.Draw(*time, Vector3(0,0, 1));

#ifdef _DEBUG
	if (test_flag) {
		SpriteBatch.DrawString(time_over_font, Vector2(130, 100), Color(255,255, 255, StringAlpha()), _T("�G���j�{�[�i�X"));
		SpriteBatch.DrawString(time_over_font, Vector2(200, 150), Color(255,255, 255, StringAlpha()), _T("�{���b"));
	}
#endif
	if(now_time > time_over)
		SpriteBatch.DrawString(time_font, Vector2(260, 10), TimeColor(), _T("%.3f"), TimeManager::Instance().GetTimeLeft());
	else {
		SpriteBatch.DrawString(time_over_font, Vector2(230, 25), Color_Red, _T("TIME OVER"));
		//finish
		SpriteBatch.Draw(*ui, Vector3(450, 320, 1), RectWH(400, 0, 750, 64), Color(255, 255, 255, SpriteAlpha()));
	}
}