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

	std::ifstream _infile(file_path);

	std::istringstream _ss;

	std::string _line;

	while (true)
	{
		if (_infile.eof())
			break;

		getline(_infile, _line);

		if (_line[0] != '#') {
			_ss = std::istringstream(_line);
			float date;
			_ss >> date;
			_filedata.push_back(date);
		}
	}
}