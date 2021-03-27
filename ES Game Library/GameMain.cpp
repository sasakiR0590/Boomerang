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

	//_count   = 0;
	//_prpos    = Vector3_Zero;
	//_fieldpos = Vector3_Zero;
	//_boomerangpower = 0.0f;
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	
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
	enemymanager->Update();
	ovserver->Update(playermanager, enemymanager);

	GraphicsDevice.SetCamera(camera);

	//_count = playermanager->CallOnCollisionEnter();
	//_prpos = playermanager->Position();
	//_fieldpos = fieldManeger->Position();
	//_boomerangpower = playermanager->Power();
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	auto player = playermanager->GetModel();

	camera->SetLookAt(player->GetPosition() + -player->GetFrontVector() * 5 + Vector3(0, 7, 0), player->GetPosition() + player->GetUpVector(), Vector3_Up);
	GraphicsDevice.SetCamera(camera);

	playermanager->Draw();
	enemymanager->Draw();
	fieldManeger->Draw();

	SpriteBatch.Begin();
	
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
