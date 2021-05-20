#include"MainGame.h"
MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

bool MainGame::Initialize()
{
	return true;
}

int MainGame::Update()
{
	return 0;
}

void MainGame::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}

void MainGame::Draw3D()
{
}
