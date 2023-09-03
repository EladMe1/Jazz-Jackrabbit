#pragma once

#include <SFML/Graphics.hpp>


class Direction {
public:
	Direction();
	~Direction();
	sf::Vector2f getDirection(sf::Keyboard::Key key);

private:
};