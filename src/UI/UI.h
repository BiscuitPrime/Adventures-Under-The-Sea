#pragma once
/*
*	Header used by the UI class of the game
*/
#include <iostream>
#include <../imgui/imgui.h>
#include <../imgui/imgui-SFML.h>
#include <Assets/Definitions.h>
#include <Assets/GameAssets.h>

class UI {
private:
	GameAssets ga;
public:
	UI(GameAssets gameAssets);
	void displayStatisticsUI(int hp,int oxygenLeft);
	void warning(std::string str);
	int startUI();
};