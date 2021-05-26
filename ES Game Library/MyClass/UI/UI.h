#pragma once

#include "../../ESGLib.h"
#include "../../StdAfx.h"
#include "../TimeManager/TimeManager.h"
#include "../PlayerManager/Boomerang/Boomerang.h"

class UI {
public:
	UI::UI();
	UI::~UI();
	bool Initialize();
	int  Update();
	void Draw();
private:
	Boomerang boomerang;

	int  SpriteAlpha();
	int  StringAlpha();
	bool SceneFlag();
	void Sound();

	Color TimeColor();
	Color color;
	SPRITE start_finish,combo,time;
	FONT time_font,time_over_font;
	SOUND start,end;

	const float time_over = 0.9f;
	bool  time_over_flag = false;
	bool  test_flag = false;
	bool  next_scene_flag = false;
	int   sprite_alpha = MIN_ALPHA;
	int   string_alpha = MIN_ALPHA;
	int   count        = MIN_COUNT;
	float frame        = MIN_FRAME;
	int   sound_state = SE_START;

	enum sound { SE_START,SE_END,NUM };
	enum Alpha { MIN_ALPHA  =  0, ALPHA_NUM  =   2, MAX_ALPHA = 255 };
	enum Time  { START      = 60, HARF       =  30, END       = 10  };
	enum Frame { MIN_FRAME  =  0, MAX_FRAME  = 360 };
	enum Count { MIN_COUNT  =  0, MAX_COUNT  =   3 };
protected:
};