#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"
#include "Resources.h"
#include "Controller.h"



class Menu
{
public:
	Menu();
	Menu(const float& width, const float& height);
	~Menu();
	void run();
	void draw();
	void createMenu();
	void drawMenuBg();
	void drawMenuButton();
	void handleMenuEvents();
	void showChoice(int& index);
	void handlePressEnter(int& index);
	void playMusic();
	void createHelp();
private:
	sf::RenderWindow m_menuWindow;
	void createWindow();
	float m_width;
	float m_height;
	std::vector<sf::Text>m_menuButtons;
	int m_choseIndex;
	sf::Sound m_sound;
};
