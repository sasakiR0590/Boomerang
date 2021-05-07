#pragma once

#include "../../ESGLib.h"
#include <sstream>
#include <codecvt>

using namespace std;

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

//! @fn  �������Path�ϊ�
static std::wstring ConvertFilePath(string path)
{
	auto filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(path);
	return filepath;
}