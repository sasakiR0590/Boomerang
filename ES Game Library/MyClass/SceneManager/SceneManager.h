#pragma once
#include "../../ESGLib.h"
#include"BaseScene/BaseScene.h"
class SceneManager
{
public:
	SceneManager();
	SceneManager(int combo);
	~SceneManager();

	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	};

	bool Initialize(string scene);
	int Update();
	void Draw();
	void ChangeScene(string scene);
	void AddCombo();

	void SetCombo(int combo);
	int GetCombo();

private:
	std::unique_ptr<BaseScene> _scene;
	int _combo;
};
