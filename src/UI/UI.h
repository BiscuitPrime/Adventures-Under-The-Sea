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
	sf::Texture warningOxygenTexture;
	sf::Texture warningHealthTexture;
public:
	UI(sf::Texture oxygenTexture, sf::Texture healthTexture);
	void displayStatisticsUI(int hp,int oxygenLeft) const;
	void warningOxygen() const;
	void warningHealth(bool oxy) const;
	int startUI() const;
	void inputUI(std::string input) const;
	void enemyUI(std::string name, int hp, sf::Sprite enemySprite) const;
};