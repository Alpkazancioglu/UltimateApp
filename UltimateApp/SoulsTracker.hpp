#pragma once
#include <string>
#include <vector>
#include "iostream"
#include <unordered_map>

class SoulsTracker
{
public:
	SoulsTracker() = default;
	~SoulsTracker() = default;
	struct m_BossInfo {
		std::string name;
		bool isDead = false;
	};
	
		

	std::unordered_map<std::string,std::unordered_map<std::string, std::vector<m_BossInfo>>> list;

	
	void Print();
	
	int GetTotalBossCount(const std::string& Area);
	int GetTotalBossCount();
	int GetSlayedBossCount(const std::string& Area);
	int GetSlayedBossCount();

private:

};

