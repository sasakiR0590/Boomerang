#pragma once
#include "../../ESGLib.h"

class TimeManager
{
private:
	TimeManager(const TimeManager&) = delete;
	void operator=(const TimeManager&) = delete;



public:
	TimeManager();
    ~TimeManager();

	static TimeManager& Instance() {
		static TimeManager instance;
		return instance;
	};

	void Initialize();
	void Update();
	
	//���b���������̎擾
	inline float GetTime()		const { return time; }
	//�c�莞�Ԃ̎擾
	inline float GetTimeLeft()  const { return limitTime - time; }
	bool StartFlag();
	void AddTime(float count) { limitTime += count; }
private:
	inline float GetLimitTime() const { return limitTime; }
	int GetTimeMinutes();
	int GetTimeSeconds();
	int GetTimeOnesPlace();
	int GetTimeTensPlace();
	int Countdown();
	float GetStartTime();
	float GetTransitionTimer() const { return transition_time; }
	//! ��������
	float limitTime;
	float time;

	//! �I����̃^�C�}�[
	float transition_time;
	bool game_end;

	//! �J�E���g�_�E��
	float startTime;
	int countTime;

	bool startFlag;
	
	};

