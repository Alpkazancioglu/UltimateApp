#include "Gui.hpp"

void DisplayGui(Words& words)
{
    static Menu currentMenu = Menu::Word;

    if (ImGui::Begin("word", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus))
    {


        ImGui::SetWindowPos({ 0,0 });
        ImGui::SetWindowSize({ 1600,900 });
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::Button("WordQuiz"))
            {
                currentMenu = Menu::Word;
            }
            ImGui::SameLine();

            if (ImGui::Button("SoulsTracker"))
            {
                currentMenu = Menu::Souls;
            }
                
            ImGui::EndMenuBar();
        }
        
        switch (currentMenu)
        {
        case Menu::Word:
            WordMenu(words);
            break;
        case Menu::Souls:
            SoulsMenu();
            break;
        default:
            break;
        }

        

        ImGui::End();
    }

}

void WordMenu(Words& words)
{
    if (ImGui::Begin("words",nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        for (size_t i = 0; i < words.list.size(); i++)
        {

            std::string list = words.list[i].english + " = [";

            for (int j = 0; j < words.list[i].turkish.size(); j++)
            {

                list += words.list[i].turkish[j] + ((j == (words.list[i].turkish.size() - 1)) ? "]" : ", ");


            }
            ImGui::Text(list.c_str());


        }
        static char wordEnglish[32];
        static char wordTurkish[32];

        ImGui::Separator();
        ImGui::InputText("English", wordEnglish, IM_ARRAYSIZE(wordEnglish));
        ImGui::InputText("Turkish", wordTurkish, IM_ARRAYSIZE(wordTurkish));

        if (ImGui::Button("Add"))
        {
            words.AddWord(wordEnglish, wordTurkish);
            memset(wordEnglish, 0, sizeof(wordEnglish));
            memset(wordTurkish, 0, sizeof(wordTurkish));
        }
        
        ImGui::End();
    }

    if (ImGui::Begin("WordQuiz", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        static bool shouldStart = false;
        static bool isGameEnded = false;
        static std::vector<int> indexs;
        static int TrueCounter = 0;
        static int FalseCounter = 0;
        static int indexCounter = 0;
        ImGui::Text("Welcome The Word Quiz");

        if (!shouldStart)
        {
            if (ImGui::Button("Start"))
            {
                shouldStart = true;
                indexs = words.GiveRandomIndexArray();
                for (size_t i = 0; i < indexs.size(); i++)
                {
                    std::cout << indexs[i] << "\n";
                }
            }
        }
        else
        {
            if (!isGameEnded)
            {
                static char answer[32];
                ImGui::Text("English word is %s", words.list[indexs[indexCounter]].english.c_str());
                ImGui::Text("Turkish meaning is ");
                ImGui::SameLine();
                ImGui::InputText(" ", answer, IM_ARRAYSIZE(answer));
                ImGui::SameLine();
                if (ImGui::Button("done"))
                {
                    m_Word word;
                    word.english = words.list[indexs[indexCounter]].english;
                    word.turkish.push_back(answer);
                    words.IsWordInTheList(word) ? TrueCounter++ : FalseCounter++;

                    *answer = {};

                    if (indexCounter == indexs.size() - 1)
                    {
                        std::cout << "Game Over   Score :: " << TrueCounter << "\n";
                        indexCounter++;
                        isGameEnded = true;
                    }
                    else
                    {
                        indexCounter++;
                    }
                }
                ImGui::Text("True Answers = %d   ", TrueCounter);
                ImGui::SameLine();
                ImGui::Text("False Answers = %d", FalseCounter);
                float bar = (1.0f / (indexs.size())) * static_cast<float>(TrueCounter);
                std::cout << bar << "\n";
                ImGui::ProgressBar(bar);
            }
            else
            {
                ImGui::Text("Game Is Ended ");
                ImGui::Text("True Answers = %d   ", TrueCounter);
                ImGui::SameLine();
                ImGui::Text("False Answers = %d", FalseCounter);
                float bar = (1.0f / (indexs.size())) * static_cast<float>(TrueCounter);
                ImGui::ProgressBar(bar);
                if (ImGui::Button("Reset"))
                {
                    shouldStart = false;
                    isGameEnded = false;
                    TrueCounter = 0;
                    FalseCounter = 0;
                    indexCounter = 0;

                }
            }
           

        }


        ImGui::End();
    }

}

void SoulsMenu()
{

    if (ImGui::Begin("SoulsTracker"))
    {
        
    }

}
