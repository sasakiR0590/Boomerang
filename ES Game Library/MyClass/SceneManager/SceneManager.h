#pragma once
#include "../../ESGLib.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	};

	void Initialize();
	void Update();
	void Draw();
private:
};
