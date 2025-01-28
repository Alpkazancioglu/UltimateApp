#pragma once
#include "Translator.hpp"
#include "imgui.h"

enum class Menu
{
	Word,Souls
};


void DisplayGui(Words& words);
void WordMenu(Words& words);
void SoulsMenu();
