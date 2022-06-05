#pragma once
/*
*	Header used by the UI class of the game
*/
#include <iostream>
#include <../imgui/imgui.h>
#include <../imgui/imgui-SFML.h>
#include <Assets/Definitions.h>

class UI {
public:
	UI();
	static void displayStatisticsUI(int hp,int oxygenLeft);
	static void warning(std::string str);
	static int startUI();
};