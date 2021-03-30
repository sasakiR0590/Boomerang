#include"LoadCSV.h"
#include<fstream>
#include<sstream>
#include<codecvt>
LoadCSV::LoadCSV()
{
	_linecount   = 0;
}

LoadCSV::~LoadCSV()
{

}

void LoadCSV::LoadStatus(string filename)
{
	std::wstring file_path = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(filename);

	std::ifstream infile(file_path);

	std::string dummy_line;

	while (true)
	{
		if (infile.eof())
			break;

		char a;
		infile >> a;
		if (a != '#') {
			float date;
			infile >> date;
			_filedata.push_back(date);
		}

		getline(infile, dummy_line);
	}
}