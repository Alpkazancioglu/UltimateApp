#include "Translator.hpp"


Words::Words()
{
}

Words::~Words()
{

}

void Words::AddWord(const std::string& english, const std::string& turkish)
{
	
	m_Word word;
	
	if (turkish == "")
	{
		std::cout << "Empty strings not allowed\n";
		return;
	}

	for (auto& it : list)
	{
		if (it.english == english)
		{
			for(auto& word:it.turkish)
			{
				if (word == turkish)	return;
			}
			it.turkish.push_back(turkish);
			return;
		}
	}
	word.english = english;
	word.turkish.push_back(turkish);

	std::sort(list.begin(), list.end());
	list.push_back(word);
	

}

void Words::DeleteWord()
{


}

void Words::PrintList()
{
	
	for (size_t i = 0; i < list.size(); i++)
	{
		std::cout << list[i].english << " = ";
		for (int j = 0; j < list[i].turkish.size(); j++)
		{
			std::cout << list[i].turkish[j] << ((j == (list[i].turkish.size()-1)) ? "\n" : ",");
		}
		
		
	}
}

std::vector<m_Word> Words::GetList() const
{
	return list;
}

void Words::LoadList(std::vector<m_Word>& list)
{
	this->list = list;
	
}

std::vector<int> Words::GiveRandomIndexArray() const
{
	std::vector<int> indexs;
	

	for (size_t i = 0; i < list.size(); i++)
	{
		indexs.push_back(i);
	}

	std::random_shuffle(indexs.begin(),indexs.end());
	return indexs;
}

bool Words::IsWordInTheList(m_Word& word) const
{
	for (auto& it : list)
	{
		if (it.english == word.english)
		{
			for (auto& wt : it.turkish)
			{
				if (wt == word.turkish[0])	return true;
			}
		}
	}
	
	return false;
}

bool Words::DeleteWordFromList(m_Word& words)
{
	int indexI = 0;
	int indexJ = 0;


	for (auto& it : list)
	{
		if (it.english == words.english)
		{
			if (words.turkish[0] == "")
			{
				list.erase(list.begin() + indexI);
				return true;
			}

			for (auto& word : it.turkish)
			{
				if (word == words.turkish[0])
				{
					it.turkish.erase(it.turkish.begin() + indexJ);
					return true;
				}
				indexJ++;
			}
			
		}
		indexI++;
	}
	std::cout << "Word Not Founded\n";
	return false;
}
