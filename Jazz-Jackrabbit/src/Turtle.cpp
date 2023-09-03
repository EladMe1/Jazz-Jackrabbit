#include "..\include\Turtle.h"
#include <iostream>

const auto turtleSpeed = 50.f;
const auto SwitchTime = sf::seconds(0.1f);

Turtle::Turtle()
	:m_direction(1)
{
}

Turtle::Turtle(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size,int level)
	:MovingObject(texture, pos, size),m_level(level)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);

	if (m_level == LEVEL1)
	{
		m_sprite.setTextureRect(sf::IntRect(MIDDLE1, MIDDLEY1, XPOINT1, YPOINT1));
	}

	else if (m_level == LEVEL2)
	{
		m_sprite.setTextureRect(sf::IntRect(XT3, YT3, W1T3, H1T3));
	}

	else if (m_level == LEVEL3)
	{
		m_sprite.setTextureRect(sf::IntRect(XT2, YT2, WT2, HT2));
	}
	
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));

	m_dir = sf::Vector2f(1, 0);

	m_direction = DIRECTION::RIGHT;
	
	if (m_level == 1)
	{
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE1, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE1 + XPOINT1, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE1 + XPOINT1 * 2, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE1 + XPOINT1 * 3, MIDDLEY1, XPOINT1, YPOINT1));

		m_map[DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE1 - XPOINT1, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE1 - XPOINT1 * 2, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE1 - XPOINT1 * 3, MIDDLEY1, XPOINT1, YPOINT1));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE1 - XPOINT1 * 4, MIDDLEY1, XPOINT1, YPOINT1));
	}

	else if (m_level == 2)
	{
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2, WT2, WT3, HT3));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2 + WT3, WT2, WT3, HT3));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2 + WT3 * 2, WT2, WT3, HT3));

		m_map[DIRECTION::LEFT].push_back((sf::IntRect(XT2, XT2, WT3, HT3)));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(XT2 + WT3, XT2, WT3, HT3));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(XT2 + WT3 * 2, XT2, WT3, HT3));
	}

	else if (m_level == 3)
	{
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2, YT2, WT2, HT2));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2 + WT2, YT2, WT2, HT2));
		m_map[DIRECTION::RIGHT].push_back(sf::IntRect(XT2 + WT2 * 2, YT2, WT2, HT2));

		m_map[DIRECTION::LEFT].push_back(sf::IntRect(XT2 - WT2, YT2, WT2, HT2));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(XT2 - WT2 * 2, YT2, WT2, HT2));
		m_map[DIRECTION::LEFT].push_back(sf::IntRect(XT2 - WT2 * 3, YT2, WT2, HT2));
	}

}

void Turtle::move(sf::Time time)
{	
	m_sprite.move(m_dir*turtleSpeed * time.asSeconds());
	update(time);
}

void Turtle::update(sf::Time time)
{
	++m_textIndex;

	if (m_level == 1)
	{
		m_textIndex %= 4;
	}

	else if (m_level == 2)
	{
		m_textIndex %= 3;
	}
	else if (m_level == 3)
	{
		m_textIndex %= 3;
	}
	m_sprite.setTextureRect(m_map[m_direction].at(m_textIndex));
}

void Turtle::setDirection(const sf::Vector2f& pos)
{
	m_dir.x *= pos.x;
}

void Turtle::switchDir()
{
	if (m_dir.x == 1)
	{
		m_direction = DIRECTION::LEFT;
		return;
	}

	else if (m_dir.x == -1)
	{
		m_direction == DIRECTION::RIGHT;
		return;
	}
}

void Turtle::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Turtle::handleCollision(Jazz& jazz)
{
	jazz.handleCollision(*this);	
}

void Turtle::handleCollision(Brick& brick)
{
}

void Turtle::handleCollision(Carrot& carrot)
{
}

void Turtle::handleCollision(Coin& coin)
{
}

void Turtle::handleCollision(Ammo& ammo)
{
}

void Turtle::handleCollision(Spike& Spike)
{
}

void Turtle::handleCollision(Exit& exit)
{
}

void Turtle::handleCollision(Turtle& turtle)
{
}



