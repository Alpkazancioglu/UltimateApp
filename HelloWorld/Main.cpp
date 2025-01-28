#include <iostream>
#include <string>
#include "Translator.hpp"
#include "FileHandler.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "Gui.hpp"


int main()
{
    std::srand(std::time(0));


    Words words;
    SaveFile::ReadFromFile("WordDataBase.json", words);
    SaveFile::PrintFile("EldenRingBosses.json");



    


    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               
    
    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(DARKGRAY);


        DisplayGui(words);
        



       

        rlImGuiEnd();
        EndDrawing();
        
    }


    SaveFile::WriteToFile("WordDataBase.json", words);

    rlImGuiShutdown();
    CloseWindow();      

}