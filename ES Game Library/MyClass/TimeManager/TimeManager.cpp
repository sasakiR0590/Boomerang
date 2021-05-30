#include "TimeManager.h"
#include"../Data/WordsTable.h"
TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::Initialize()
{
	limitTime  = MAXTIME;
	time       = 0.0f;

	startTime  = 181.0f;
	countTime  = 3;

	startFlag = false;

	game_end = false;

	transition_time = 0;
}
 

void TimeManager::Update()
{

	if (startFlag == true) {
		if (time < limitTime - 0.9f)
		{
			time += (float)GameTimer.GetElapsedSecond();
		}
	}
	
	if (GetTimeLeft() <= 1) {
		game_end = true;
		if (game_end == true)
		{
			transition_time += (float)GameTimer.GetElapsedSecond();
		}
	}

	startTime--;
	
	if (startTime == 180) {
		countTime = 3;
	}
	if (startTime == 120) {
		countTime = 2;
	}
	if (startTime == 60) {
		countTime = 1;
	}
	if (startTime == 0) {
		countTime = 0;
	}
	if (startTime == -60) {
		countTime = -1;
		startTime = -60;
	}

	

	if (countTime == -1) {
		startFlag = true;
	}
}

//! @fn �������ԁi���j
//! @return �������Ԃ𕪂ŕԂ�
int TimeManager::GetTimeMinutes()
{
	int ret = 0;

	ret = ((int)(GetTimeLeft()) % 3600) / 60;

	return ret;
}

//! @fn �������ԁi�b�j
//! @return �������Ԃ�b�ŕԂ�
int TimeManager::GetTimeSeconds()
{
	int ret = 0;

	ret = (int)( GetTimeLeft() ) % 60;

	return ret;
}

int TimeManager::GetTimeTensPlace()
{
	int ret = 0;

	ret = (int)(GetTimeLeft()) % 60 / 10;

	return ret;
}

int TimeManager::GetTimeOnesPlace()
{
	int ret = 0;

	ret = (int)(GetTimeLeft()) % 60 % 10;

	return ret;
}

//! @fn �J�E���g�_�E��
//! @return �J�E���g�_�E���̕b��Ԃ�
int  TimeManager::Countdown()
{
	return countTime;
}

//! @fn �J�E���g�_�E��
//! @return �J�E���g�_�E����float�ŕԂ�
float TimeManager::GetStartTime()
{
	return startTime;
}

//! @fn �Q�[�����n�܂��Ă��邩�ǂ���
//! @return �Q�[�����X�^�[�g���Ă����true,�X�^�[�g���Ă��Ȃ����false
//! @detail �Q�[�����X�^�[�g���Đ������Ԃ��v�����Ă��邩�ǂ���
bool TimeManager::StartFlag()
{ 
	return 	startFlag;
}



