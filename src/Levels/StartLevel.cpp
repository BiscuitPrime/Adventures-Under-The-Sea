/*
*	Source code for Start Level class
*/
#include "StartLevel.h"

StartLevel::StartLevel(int id, GameManager* gameManager) : Level{id,nullptr}
{}

void StartLevel::startLoop(sf::RenderWindow* window)
{
	UI::startUI();
	ImGui::SFML::Render(*window);
	window->display();
}