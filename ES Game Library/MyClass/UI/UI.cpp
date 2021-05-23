#include "UI.h"

UI::UI() {

}

UI::~UI() {

}

bool UI::Initialize() {
	time_font      = GraphicsDevice.CreateSpriteFont(_T("ü‡ñæí© Demibold"), 80);
	time_over_font = GraphicsDevice.CreateSpriteFont(_T("ü‡ñæí© Demibold"), 50);
	ui             = GraphicsDevice.CreateSpriteFromFile(_T("ui/STARTÅAÇeÇhÇmÇhÇrÇg.png"));
	time           = GraphicsDevice.CreateSpriteFromFile(_T("ui/TIME_2.png"));
	return true;
}

int UI::Update() {
	SpriteAlpha();
	return 0;
}

int  UI::SpriteAlpha() {
	if (!TimeManager::Instance().StartFlag()              && sprite_alpha < MAX_ALPHA ||
		TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA)
		sprite_alpha += 2;
	else
		sprite_alpha = MIN_ALPHA;

	return sprite_alpha;
}


Color UI::TimeColor() {
	float time = TimeManager::Instance().GetTimeLeft();
	if (time < START)
		color = Color_White;
	if (time < HARF)
		color = Color_Orange;
	if (time < END)
		color = Color_Red;
	return color;
}

void UI::Draw() {
	//start
	if(!TimeManager::Instance().StartFlag())
	SpriteBatch.Draw(*ui, Vector3(450,320,1),RectWH(0,0,300,64),Color(255,255, 255, SpriteAlpha()));

	SpriteBatch.Draw(*time, Vector3(0,0, 1));

	if(TimeManager::Instance().GetTimeLeft() > time_over)
		SpriteBatch.DrawString(time_font, Vector2(260, 10), TimeColor(), _T("%.3f"), TimeManager::Instance().GetTimeLeft());
	else {
		SpriteBatch.DrawString(time_over_font, Vector2(230, 25), Color_Red, _T("TIME OVER"));
		//finish
		SpriteBatch.Draw(*ui, Vector3(450, 320, 1), RectWH(400, 0, 750, 64), Color(255, 255, 255, SpriteAlpha()));
	}
}