#pragma once

#include <fstream>
#include "SFML/Graphics.hpp"
#include "Resources.h"
#include "Board.h"

class Controller {
public:
	Controller();
	~Controller();
	void run();
	void createWindow();
	void handleEvent();
	void draw();
	void handleCollision(sf::Time delta);
	bool levelComplete();
	void nextLevel();
	void endGame();
	void chekIfLose();

private:
	sf::Clock m_gameClock;
	sf::View m_gameView;
	sf::RectangleShape m_bg;
	std::fstream m_file;
	int m_level;
	sf::RenderWindow m_gameWindow;
	Board m_board;
	sf::Time m_timer = {};
	sf::Sound m_soundEffect;
};