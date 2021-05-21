#include"../../../BaseScene.h"
class TitleScene:public BaseScene
{
public:
	TitleScene();
	virtual ~TitleScene();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;

private:
	SPRITE bg;
};