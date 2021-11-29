#pragma once
#include<string>
#include"SDL.h"

namespace henry
{
	void SetFilePath(const std::string& pathname);
	std::string GetFilePath();
	bool ReadFileToString(const std::string& filename, std::string& filestring);
}