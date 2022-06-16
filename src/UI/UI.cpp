#include "UI.h"
#include "UI.h"
#include "UI.h"
#include "UI.h"
/*
*	Source code for the UI class
*/
#include <UI/UI.h>



//constructor
UI::UI(sf::Texture oxytext, sf::Texture healthtext)
{
	warningOxygenTexture = oxytext;
	warningHealthTexture = healthtext;
}

//method used to display the oxygen of the player
void UI::displayStatisticsUI(int hp, int oxygenLeft)
{
	ImGui::SetNextWindowPos(ImVec2(20, 20));
	ImGui::SetNextWindowSize(ImVec2(170, 100));
	ImGui::Begin("Player Statistics");
	ImGui::Text("Oxygen levels :");
	ImGui::Text(std::to_string(oxygenLeft).c_str());
	ImGui::Text("HP :", sf::Color::Blue);
	ImGui::Text(std::to_string(hp).c_str());
	ImGui::End();
}

//method used to display a warning message in case of low oxygen
void UI::warningOxygen()
{
	ImGui::SetNextWindowPos(ImVec2(500, 20));
	ImGui::SetNextWindowSize(ImVec2(500, 150));
	ImGui::Begin("WARNING OXYGEN");
	sf::Sprite sprite;
	sprite.setTexture(warningOxygenTexture);
	ImGui::Image(sprite);
	std::string display = "Oxygen low, please advise quickly";
	ImGui::Text(display.c_str());
	ImGui::End();
}

//method used to display a warning message in case of low oxygen
void UI::warningHealth(bool oxy)
{
	if (oxy == true) { ImGui::SetNextWindowPos(ImVec2(500, 180)); }
	else { ImGui::SetNextWindowPos(ImVec2(500, 20)); }
	ImGui::SetNextWindowSize(ImVec2(500, 150));
	ImGui::Begin("WARNING HEALTH");
	sf::Sprite sprite;
	sprite.setTexture(warningHealthTexture);
	ImGui::Image(sprite);
	std::string display = "Health low, please advise quickly";
	ImGui::Text(display.c_str());
	ImGui::End();
}

//Starting UI
int UI::startUI()
{
	ImGui::SetNextWindowPos(ImVec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	ImGui::Begin("");
	if (ImGui::Button("START GAME"))
	{
		return 0;
	}
	ImGui::End();
	return -1;
}

//input attack ui :
void UI::inputUI(std::string input) const
{
	ImGui::SetNextWindowPos(ImVec2(20, 150));
	ImGui::SetNextWindowSize(ImVec2(200, 70));
	ImGui::Begin("SUGGESTION");
	std::string display = "PLEASE CHOOSE A MOVEMENT";
	if (input == "attack") {
		display = "PLEASE CHOOSE AN ATTACK";
	}
	ImGui::Text(display.c_str());
	ImGui::End();
}

//enemy UI display :
void UI::enemyUI(std::string name, int hp, sf::Sprite enemySprite) const
{
	ImGui::SetNextWindowPos(ImVec2(1200, 20));
	ImGui::SetNextWindowSize(ImVec2(200, 200));
	ImGui::Begin("Current Enemy");
	ImGui::Image(enemySprite);
	std::string display = "Name :";
	ImGui::Text(display.c_str());
	ImGui::Text(name.c_str());
	display = "HP :";
	ImGui::Text(display.c_str());
	ImGui::Text(std::to_string(hp).c_str());
	ImGui::End();
}