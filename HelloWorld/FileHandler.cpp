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

bool SaveFile::IsFileEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}
