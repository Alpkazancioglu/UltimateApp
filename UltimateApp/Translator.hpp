#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <time.h>

struct m_Word
{
	std::string english;
	std::vector<std::string> turkish;

	bool operator < (const m_Word& str) const
	{
		return english < str.english;
	}
};


class Words
{
	

public:
	Words();
	~Words();
	void AddWord(const std::string& english,const std::string& turkish);
	void DeleteWord();
	void PrintList();
	std::vector<m_Word> GetList() const;
	void LoadList(std::vector<m_Word>& list);
	std::vector<int> GiveRandomIndexArray() const;
	bool IsWordInTheList(m_Word& word) const;
	std::vector<m_Word> list;
	bool DeleteWordFromList(m_Word& words);

};
