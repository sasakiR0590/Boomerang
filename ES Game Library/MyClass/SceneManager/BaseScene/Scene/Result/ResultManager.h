#include"../../BaseScene.h"
class ResultManager :public BaseScene
{
public:
	ResultManager();
	virtual ~ResultManager();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;

private:
};