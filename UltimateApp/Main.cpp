#include <iostream>
#include <string>
#include "Translator.hpp"
#include "FileHandler.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "Gui.hpp"
#include "globalVariables.hpp"
#include "TextureHandler.hpp"

int main()
{
    std::srand(std::time(0));

    
    
    SaveFile::ReadFromFile(SaveFile::getRelativePath("WordDataBase.json"), words);
    SaveFile::ReadFromFile(SaveFile::getRelativePath("EldenRingBosses.json"), souls);
    

    

    const int screenWidth = 1600;
    const int screenHeight = 900;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    SetTargetFPS(60);               
    
    rlImGuiSetup(true);
    
    
    eldenRingTexture = LoadTextureFromImage({ ELDENRINGTEXTURE_DATA,ELDENRINGTEXTURE_WIDTH,ELDENRINGTEXTURE_HEIGHT,1,ELDENRINGTEXTURE_FORMAT });
    englishTexture = LoadTextureFromImage({ ENGLISHTEXTURE_DATA ,ENGLISHTEXTURE_WIDTH,ENGLISHTEXTURE_HEIGHT,1,ENGLISHTEXTURE_FORMAT });


    while (!WindowShouldClose())
    {

        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(DARKGRAY);
       
        DisplayGui();
  
        rlImGuiEnd();
        EndDrawing();
        
    }


    SaveFile::WriteToFile(SaveFile::getRelativePath("WordDataBase.json"), words);
    SaveFile::WriteToFile(SaveFile::getRelativePath("EldenRingBosses.json"), souls);


    rlImGuiShutdown();
    CloseWindow();      

}