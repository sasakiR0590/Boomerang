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

	int SpriteAlpha();
	Color TimeColor();
	Color color;
	SPRITE ui,time;
	FONT time_font,time_over_font;
	const float time_over = 0.9f;
	int   combo_counter = 0;
	bool  time_over_flag = false;
	bool  test_flag = false;
	float frame = 0.0f;

	int   sprite_alpha = MIN_ALPHA;

	enum { BONUS_FRAME = 120 };
	enum { MIN_ALPHA = 0, MAX_ALPHA = 255 };
	enum Time { START = 61, HARF = 30, END = 10 };
protected:
};