/*
*	Source code for the UI class
*/
#include <UI/UI.h>

//constructor
UI::UI()
{}

//method used to display the oxygen of the player
void UI::displayOxygenUI(int oxygenLeft)
{
	ImGui::Begin("Player Statictics");
	ImGui::Text("Oxygen levels :");
	ImGui::Text(std::to_string(oxygenLeft).c_str());
	ImGui::End();
}

//method used to display the health of the player
void UI::displayHealthUI(int hp)
{
	ImGui::Begin("Player Statictics");
	ImGui::Text("HP :",sf::Color::Blue);
	ImGui::Text(std::to_string(hp).c_str());
	ImGui::End();
}

//method used to display a warning message in case of low oxygen
void UI::warning(std::string str)
{
	ImGui::SetNextWindowSize(ImVec2(500, 70));
	ImGui::Begin("WARNING");
	std::string display = str + " low, please advise quickly";
	ImGui::Text(display.c_str());
	ImGui::End();
}
