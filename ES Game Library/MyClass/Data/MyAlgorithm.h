#pragma once

#include "../../ESGLib.h"
#include"WordsTable.h"
#include <codecvt>
#include <fstream>
//! @fn �l���w�肳�ꂽ�͈͂Ɏ��߂�֐�
//! @param (value) �͈͓��Ɏ��߂�l
//! @param (min) ���߂�l�̉����l 
//! @param (max) ���߂�l�̏���l
static float Clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return value;
}

// @fn
//int�^�̃��b�v�A���E���h�^�֐��i����l�ɒB�������ɉ����l�ɖ߂��j
static int IntWrap(int x, int low, int high)
{
	assert(low < high && "�����l������l�𒴂��Ă��܂�");
	const int n = (x - low) % (high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

// @fn
//float�^�̃��b�v�A���E���h�^�֐��i����l�ɒB�������ɉ����l�ɖ߂��j
static float FloatWrap(float x, float low, float high)
{
	assert(low < high && "�����l������l�𒴂��Ă��܂�");
	const float n = std::fmod(x - low, high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

//@fn �������Path�ϊ�
//@param (path) �ϊ����镶���� 
static ::wstring ConvertStringFilePath(string pathname)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(pathname);
}
//@fn ��������t�@�C���ǂݍ��݂Ɏg����悤�ɕϊ�
//@param (path) �ϊ����镶���� 
static LPCWSTR ConvertStringFileName(string filename)
{
	static ::wstring path;
	path = ConvertStringFilePath(filename);
	return path.c_str();
}
static std::vector<int>GetSaveData()
{
	std::ifstream datafile("Score/Score.txt");
	int data[SaveData::ALLCOUNT]{};
	std::vector<int> savedata;

	datafile >> data[EnemyCount]  >> data[Combo];
	for (int i = 0; i < SaveData::ALLCOUNT; i++)
	{
		savedata.push_back(data[i]);
	}

	return savedata;
}