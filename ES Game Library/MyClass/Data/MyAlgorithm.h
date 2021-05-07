#pragma once

#include "../../ESGLib.h"
#include <sstream>
#include <codecvt>

using namespace std;

//! @fn 値を指定された範囲に収める関数
//! @param (value) 範囲内に収める値
//! @param (min) 収める値の下限値 
//! @param (max) 収める値の上限値
static float Clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return value;
}

//! @fn  文字列のPath変換
static std::wstring ConvertFilePath(string path)
{
	auto filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(path);
	return filepath;
}