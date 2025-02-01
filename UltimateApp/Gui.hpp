#pragma once
#include "Translator.hpp"
#include "imgui.h"
#include "SoulsTracker.hpp"
#include "globalVariables.hpp"
#include "TextureHandler.hpp"
#include "raylib.h"


enum class Menu
{
	Word,Souls
};


void DisplayGui();
void WordMenu();
void SoulsMenu();
