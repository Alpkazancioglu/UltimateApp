#include "FileHandler.hpp"

bool SaveFile::WriteToFile(const std::string& fileLocation, Words& words)
{
    std::ofstream file(fileLocation);

    

    if (!file)
    {
        std::cout << "File Is Not Exist \n";
        return false;
    }

    json jsonFile;
    const auto list = words.GetList();

    for (size_t i = 0; i < list.size(); i++)
    {
        jsonFile[list[i].english] = list[i].turkish;
    }


    file << std::setw(4) << jsonFile;

    file.close();

    return false;
}

bool SaveFile::ReadFromFile(const std::string& fileLocation, Words& words)
{
    std::ifstream file(fileLocation);
    
    if (!file)
    {
        std::cout << "File Is Not Exist \n";
        file.close();
        return false;
    }

    if (IsFileEmpty(file))
    {
        std::cout << "File Is Empty \n";
        file.close();
        return false;
    }

    json jsonFile;
    file >> jsonFile;

    auto list = words.GetList();

    

    for (json::iterator it = jsonFile.begin(); it != jsonFile.end(); it++) {
        m_Word word;
        word.english = it.key();
        word.turkish = it.value();
        list.push_back(word);
    }

    words.LoadList(list);    

    file.close();
    return false;
}

bool SaveFile::PrintFile(const std::string& fileLocation)
{
    std::ifstream file(fileLocation);

    if (!file)
    {
        std::cout << "File Is Not Exist \n";
        file.close();
        return false;
    }

    if (IsFileEmpty(file))
    {
        std::cout << "File Is Empty \n";
        file.close();
        return false;
    }

    json jsonFile;
    file >> jsonFile;
    std::cout << std::setw(4) << jsonFile;
}

bool SaveFile::ReadFromFile(const std::string& fileLocation, SoulsTracker& soulsList)
{
    std::ifstream file(fileLocation);

    if (!file)
    {
        std::cout << "File Is Not Exist \n";
        file.close();
        return false;
    }

    if (IsFileEmpty(file))
    {
        std::cout << "File Is Empty \n";
        file.close();
        return false;
    }

    json jsonFile;
    file >> jsonFile;



    std::unordered_map<std::string, std::vector<SoulsTracker::m_BossInfo>> locations;

    for (size_t i = 0; i < jsonFile.size(); i++)
    {
        std::string location = jsonFile[i]["region_name"];
        locations[location];
        
        for (size_t j = 0; j < jsonFile[i]["bosses"].size(); j++)
        {
            SoulsTracker::m_BossInfo bossInfo;
            bossInfo.name = jsonFile[i]["bosses"][j]["boss"];
            bossInfo.isDead = jsonFile[i]["bosses"][j]["Dead"];
            locations[location].push_back(bossInfo);
        }
    }
    
    soulsList.list["EldenRing"] = locations;

    

    return false;
}

bool SaveFile::WriteToFile(const std::string& fileLocation, SoulsTracker& soulsList)
{
    std::ofstream file(fileLocation);


    if (!file)
    {
        std::cout << "File Is Not Exist \n";
        return false;
    }

    json jsonFile;
    
    for (auto&it : soulsList.list)
    {
        int i = 0;
        for (auto& it2 : it.second) //
        {
            
            std::cout << "  Location: " << it2.first << std::endl;
            jsonFile[i]["region_name"] = it2.first;
            int j = 0;
            for (auto& boss : it2.second)
            {
                jsonFile[i]["bosses"][j]["boss"] = boss.name;
                jsonFile[i]["bosses"][j]["Dead"] = boss.isDead;
                j++;
            
            }
            i++;
        }
    }

    

    file << std::setw(4) << jsonFile;

    file.close();

}

std::string SaveFile::getRelativePath(const std::string& fileName)
{
    
    std::string fileLocation = sago::getDocumentsFolder() + "/UltimateAppDataBase";
   
    
    

    for (auto& it : fileLocation)
    {
       
        
        if (it == 92) // eger it \ ye esitse
        {
            it = '/';
        }
        
    }
    if (!std::experimental::filesystem::exists(fileLocation))
    {
        std::experimental::filesystem::create_directories(fileLocation);
    }
    fileLocation += "/" + fileName;

    
    std::cout << fileLocation << "\n";
    return fileLocation;
    
}



bool SaveFile::IsFileEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}
