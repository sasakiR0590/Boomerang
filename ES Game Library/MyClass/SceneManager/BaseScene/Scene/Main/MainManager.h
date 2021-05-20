#include"../../BaseScene.h"

class MainManager :public BaseScene
{
public:
	MainManager();
	~MainManager();
	bool Initialize() override;
	void Draw2D() override;
private:
};