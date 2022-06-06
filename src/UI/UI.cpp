#include "UI.h"
#include "UI.h"
/*
*	Source code for the UI class
*/
#include <UI/UI.h>



//constructor
UI::UI(GameAssets gameAssets)
{
	ga = gameAssets;
}

//method used to display the oxygen of the player
void UI::displayStatisticsUI(int hp, int oxygenLeft)
{
	ImGui::SetNextWindowPos(ImVec2(20,20));
	ImGui::SetNextWindowSize(ImVec2(170, 100));
	ImGui::Begin("Player Statictics");
	ImGui::Text("Oxygen levels :");
	ImGui::Text(std::to_string(oxygenLeft).c_str());
	ImGui::Text("HP :", sf::Color::Blue);
	ImGui::Text(std::to_string(hp).c_str());
	ImGui::End();
}

//method used to display a warning message in case of low oxygen
void UI::warning(std::string str)
{
	ImGui::SetNextWindowPos(ImVec2(500, 20));
	ImGui::SetNextWindowSize(ImVec2(500, 150));
	ImGui::Begin("WARNING");
	sf::Texture warningtext = ga.AlertOxygen;
	sf::Sprite sprite;
	sprite.setTexture(warningtext);
	ImGui::Image(sprite);
	std::string display = str + " low, please advise quickly";
	ImGui::Text(display.c_str());
	ImGui::End();
}

int UI::startUI()
{
	ImGui::SetNextWindowPos(ImVec2(windowWidth / 2, windowHeight / 2));
	ImGui::Begin("");
	if (ImGui::Button("START GAME"))
	{
		return 0;
	}
	ImGui::End();
	return -1;
}
