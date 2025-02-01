#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Translator.hpp"
#include <fstream>
#include "json.hpp"
#include "SoulsTracker.hpp"
#include "raylib.h"
#include "platform_folders.h"
#include "experimental/filesystem"


using json = nlohmann::json;


class SaveFile
{
public:
	SaveFile() = default;
	
	static bool WriteToFile(const std::string& fileLocation,Words& words);
	static bool ReadFromFile(const std::string& fileLocation, Words& words);
	static bool PrintFile(const std::string& fileLocation);
	static bool ReadFromFile(const std::string& fileLocation, SoulsTracker& soulsList);
	static bool WriteToFile(const std::string& fileLocation, SoulsTracker& soulsList);
	static std::string getRelativePath(const std::string& fileName);
	

private:
	static bool IsFileEmpty(std::ifstream& file);
};
