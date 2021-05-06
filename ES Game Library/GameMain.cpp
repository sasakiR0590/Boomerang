// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>

bool GameMain::Initialize()
{
	WindowTitle(_T("ES Game Library"));
	playermanager->Initialize();
	enemymanager->Initialize();
	fieldManeger->Initialize();
	EffectManager::Instance().Initialize();
	player = playermanager->GetModel();

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3(1.0f, 1.0f, 1.0f);
	light.Ambient = Color(1.0f, 1.0f, 1.0f);
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	light.Specular = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	camera->SetView(Vector3(0, 0, -650), Vector3(0, 0, 0));
	camera->SetPerspectiveFieldOfView(45.0f, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	delete ovserver;
	delete enemymanager;
	delete playermanager;
	delete fieldManeger;
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	playermanager->Update();
	enemymanager->Update(playermanager);
	ovserver->Update(playermanager, enemymanager);
	EffectManager::Instance().Update();
	Effekseer.Update();
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	camera->SetLookAt(player->GetPosition() + Vector3_Backward * 5 + Vector3(0.0f, 7.0f, 0.0f), player->GetPosition() + player->GetUpVector(), Vector3_Up);
	GraphicsDevice.SetCamera(camera);
	playermanager->Draw();
	enemymanager->Draw();
	fieldManeger->Draw();
	EffectManager::Instance().Draw();

	GraphicsDevice.SetRenderState(DepthBuffer_Disable);
	GraphicsDevice.SetRenderState(DepthBufferFunction_Always);
	Effekseer.SetCamera(camera);
	Effekseer.Draw();
	GraphicsDevice.SetRenderState(DepthBufferFunction_Less);
	GraphicsDevice.SetRenderState(DepthBuffer_Enable);

	SpriteBatch.Begin();
	if (playermanager->AttackPattern() == 0) {
		SpriteBatch.DrawString(DefaultFont, Vector2(0, 0), Color(255, 255, 255), _T("サイズ拡大"));
	}
	else if (playermanager->AttackPattern() == 1) {
		SpriteBatch.DrawString(DefaultFont, Vector2(0, 0), Color(255, 255, 255), _T("飛距離が伸びる"));
	}
	else if (playermanager->AttackPattern() == 2) {
		SpriteBatch.DrawString(DefaultFont, Vector2(0, 0), Color(255, 255, 255), _T("速度が上がる"));
	}

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
