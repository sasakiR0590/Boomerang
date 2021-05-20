#pragma once
#include "../../ESGLib.h"
#include"BaseScene/BaseScene.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	};

	bool Initialize(string scene);
	int Update();
	void Draw();
	void ChangeScene(string scene);
private:
	std::unique_ptr<BaseScene> _child_scene;
};
