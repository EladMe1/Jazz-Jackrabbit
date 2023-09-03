#include "..\include\Direction.h"

Direction::Direction()
{
}

Direction::~Direction()
{
}

sf::Vector2f Direction::getDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Right:
	{
		return sf::Vector2f(1, 0);
	}
	case sf::Keyboard::Left:
	{
		return sf::Vector2f(-1, 0);
	}
	case sf::Keyboard::Up:
	{
		return sf::Vector2f(0, 1);
	}
	case sf::Keyboard::Down:
	{
		return sf::Vector2f(0, -1);
	}
	default:
		break;
	}
}
