#pragma once

#include "../../ESGLib.h"
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

// @fn
//int型のラップアラウンド型関数（上限値に達した時に下限値に戻す）
static int int_wrap(int x, int low, int high)
{
	assert(low < high && "下限値が上限値を超えています");
	const int n = (x - low) % (high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

// @fn
//float型のラップアラウンド型関数（上限値に達した時に下限値に戻す）
static float float_wrap(float x, float low, float high)
{
	assert(low < high && "下限値が上限値を超えています");
	const float n = std::fmod(x - low, high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

//! @fn  文字列のPath変換
//! @param (path) 変換する文字列 
static wstring ConvertFilePath(string path)
{
	auto filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(path);
	return filepath;
}