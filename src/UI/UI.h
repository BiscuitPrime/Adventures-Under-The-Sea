#pragma once
/*
*	Header used by the UI class of the game
*/
#include <iostream>
#include <../imgui/imgui.h>
#include <../imgui/imgui-SFML.h>

class UI {
public:
	UI();
	static void displayOxygenUI(int oxygenLeft);
	static void displayHealthUI(int hp);
	static void warning(std::string str);
};