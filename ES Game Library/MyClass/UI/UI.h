#include "../../ESGLib.h"
#include "../../StdAfx.h"

class UI {
public:
	UI::UI();
	UI::~UI();
	bool Initialize();
	int  Update();
	void Draw();
private:
	SPRITE ui;
protected:
};