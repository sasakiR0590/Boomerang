#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "Crass/Player/PlayerManeger.h"
#include "Crass/Enemy/EnemyManeger.h"
#include "Crass/Ovserver/Ovserver.h"
#include "Crass/Field/FieldManager.h"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
		playermanager = new PlayerManager;
		enemymanager  = new EnemyManager;
		ovserver      = new Ovserver;
		fieldManeger  = new FieldManeger;
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
		delete ovserver;
		delete enemymanager;
		delete playermanager;
		delete fieldManeger;
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	PlayerManager* playermanager;
	EnemyManager*  enemymanager;
	Ovserver*      ovserver;
	FieldManeger* fieldManeger;

	CAMERA camera;
	int _count;   //OnCollisionEnterが呼ばれた回数
	
	//デバック用
	//Vector3 _prpos;
	//Vector3 _fieldpos;
	//float   _boomerangpower;
};
