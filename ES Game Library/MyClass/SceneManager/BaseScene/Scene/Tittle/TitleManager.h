#include"../../BaseScene.h"

class TitleManager:public BaseScene
{
public:
	TitleManager();
	~TitleManager();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;
private:
};