#include"../../../BaseScene.h"

class MainGame :public BaseScene
{
public:
	MainGame();
	~MainGame();
	bool Initialize() override;
	int Update()override;
	void Draw2D() override;
	void Draw3D() override;
private:
};