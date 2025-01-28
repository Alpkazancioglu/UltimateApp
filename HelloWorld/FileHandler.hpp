#pragma once
#include "Translator.hpp"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class SaveFile
{
public:
	SaveFile() = default;
	
	static bool WriteToFile(const std::string& fileLocation,Words& words);
	static bool ReadFromFile(const std::string& fileLocation, Words& words);
	static bool PrintFile(const std::string& fileLocation);


private:
	static bool IsFileEmpty(std::ifstream& file);
};
