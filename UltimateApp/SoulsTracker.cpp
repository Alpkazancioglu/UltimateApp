#include "SoulsTracker.hpp"

void SoulsTracker::Print()
{
    for (auto& it : list)
    {
        std::cout << "Category: " << it.first << std::endl;
        for (auto& it2 : it.second) //
        {
            std::cout << "  Location: " << it2.first << std::endl;
            for (auto& boss : it2.second)
            {
                std::cout << "    Boss: " << boss.name
                    << ", Is Dead: " << boss.isDead << std::endl;
            }
        }
    
    }
}

int SoulsTracker::GetTotalBossCount(const std::string& Area)
{
    int bossCount = 0;
    for (auto& it : list)
    {
        for (auto& it2 : it.second) //
        {
            if (it2.first == Area)
            {
                for (auto& boss : it2.second)
                {
                    bossCount++;
                }
            }
            
        }

    }


    return bossCount;
}

int SoulsTracker::GetTotalBossCount()
{
    int bossCount = 0;
    for (auto& it : list)
    {
        for (auto& it2 : it.second) //
        {
            for (auto& boss : it2.second)
            {
                bossCount++;
            }
        }
    }

    return bossCount;
}

int SoulsTracker::GetSlayedBossCount(const std::string& Area)
{
    int slayedBossCount = 0;
    for (auto& it : list)
    {
        
        for (auto& it2 : it.second) //
        {
            if (it2.first == Area)
            {
                for (auto& boss : it2.second)
                {
                    if (boss.isDead) slayedBossCount++;
                }
            
            }
        }
    }
    return slayedBossCount;
}

int SoulsTracker::GetSlayedBossCount()
{
    int slayedBossCount = 0;
    for (auto& it : list)
    {
        
        for (auto& it2 : it.second) //
        {
            
            for (auto& boss : it2.second)
            {
                if (boss.isDead) slayedBossCount++;
            }
        }

    }
    return slayedBossCount;
}
