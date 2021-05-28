#pragma once

/**
 * @file   UI.h
 * @brief  �Q�[�����̕����E�摜�`��AMainGame���̃V�[���J�ڂ��s���Ă���N���X
 * @author Mitsuhide Kowata
 * @date   2021/05/20
 */

#include "../../ESGLib.h"
#include "../../StdAfx.h"
#include "../TimeManager/TimeManager.h"
#include "../PlayerManager/Boomerang/Boomerang.h"
#include"../EnemyManager/EnemyManeger.h"

class UI {
public:
	UI::UI();
	UI::~UI();
	bool Initialize();
	int  Update();
	void Draw();
private:
	Boomerang boomerang;

	int  SpriteAlpha();
	bool SceneFlag();
	void Sound();

	Color TimeColor();
	Color color;
	SPRITE start_finish,combo,time;
	FONT time_font,time_over_font;
	SOUND start,end;

	const float time_over = 0.9f;
	bool  time_over_flag = false;
	bool  test_flag = false;
	bool  next_scene_flag = false;
	int   sprite_alpha = MIN_ALPHA;
	int   count        = MIN_COUNT;
	int   sound_state  = SE_START;

	/**
    * @enum Sound
    * SE�̏�ԕω��p
    */
	enum Sound { SE_START,SE_END,NUM };

	/**
    * @enum Alpha
    * �摜�̃A���t�@�l�ύX�p
    */
	enum Alpha { MIN_ALPHA  =  0, ALPHA_NUM  =   2, MAX_ALPHA = 255 };

	/**
    * @enum Time
    * ���Ԃ��w�肵�������s��
    */
	enum Time  { START      = 60, HARF       =  30, END       = 10  };

	/**
    * @enum Count
    * �摜�_�ł̓_�ŉ񐔃J�E���g
    */
	enum Count { MIN_COUNT  =  0, MAX_COUNT  =   3 };
protected:
};