#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "MyClass/PlayerManager/PlayerManeger.h"
#include "MyClass/EnemyManager/EnemyManeger.h"
#include "MyClass/Ovserver/Ovserver.h"
#include "MyClass/Field/FieldManager.h"
#include "MyClass/EffectManager/EffectManager.h"
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
		Finalize();
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
	
	ANIMATIONMODEL player;
};
