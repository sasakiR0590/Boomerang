#pragma once

#include"../../ESGLib.h"

class LoadCSV {
public:
	LoadCSV::LoadCSV();
	LoadCSV::~LoadCSV();
	static LoadCSV& Instance()
	{
		static LoadCSV instance;
		return instance;
	}

    void LoadStatus(string filename);

	std::vector<float> _filedata;

	int   _linecount;
};