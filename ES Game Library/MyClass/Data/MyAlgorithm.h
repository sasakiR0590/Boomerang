#pragma once

#include "../../ESGLib.h"
#include <codecvt>

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
	auto filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(pathname);
	return filepath;
}
//@fn ��������t�@�C���ǂݍ��݂Ɏg����悤�ɕϊ�
//@param (path) �ϊ����镶���� 
static LPCWSTR ConvertStringFileName(string filename)
{
	return ConvertStringFilePath(filename).c_str();
}