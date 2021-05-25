#include "../../../BaseScene.h"

class ResultScene :public BaseScene {
public:
	ResultScene();
	virtual ~ResultScene();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;

private:
	SPRITE result;
protected:

};