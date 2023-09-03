#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Globals.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Brick.h"
#include "Turtle.h"
#include "Carrot.h"
#include "Coin.h"
#include "Ammo.h"
#include "Jazz.h"
#include "Spike.h"
#include "Exit.h"

class Jazz;
class Ammo;
class Weapon;
class Turtle;
class Carrot;
class Coin;
class Brick;
class Jazz;
class Spike;
class Exit;

class Board {
public:
	Board();
	~Board();
	bool loadMatrix();
	bool openFile();
	std::vector<std::string> getLevel();
	void loadLevel();
	void handleEvent(sf::Keyboard::Key key);
	void handleCollisions(sf::Time delta);
	void moveObjects(sf::Time time);
	void draw(sf::RenderWindow& gameWindow);
	const sf::Vector2f& getJazzPos() const;
	void fire();
	void createPuase();
	void handlePressEnter(sf::RenderWindow& window, int& index);
	bool handleClick(const sf::Vector2f& location, int& index);
	bool isLevelComlete();
	void clear();
	void addLevel() { m_level++; };
	int getMlevel() const { return m_level; };
	bool lose();

private:
	int m_row;
	int m_col;
	int m_level;
    std::fstream m_file;
	std::vector<std::string> m_matrix;
	std::vector<sf::Text>m_pauseButton;
	std::vector<sf::RectangleShape>m_hearts;
	std::vector<sf::RectangleShape>m_carrots;
	std::vector<sf::RectangleShape>m_coins;
	sf::Text m_carrotText;
	sf::Text m_coinText;
	sf::Sound m_soundEffect;

	//data structures
	std::unique_ptr<Jazz> m_jazz;
	std::vector<std::unique_ptr<MovingObject>> m_enemies;
	std::vector<std::unique_ptr<StaticObject>> m_presents;
	std::vector<std::unique_ptr<StaticObject>> m_ammos;
	std::vector<std::unique_ptr<StaticObject>> m_statics;
	std::vector<sf::RectangleShape> m_blockers;
	std::vector<std::unique_ptr<Ammo>> m_bullets;
	std::unique_ptr<Exit> m_exit;
};