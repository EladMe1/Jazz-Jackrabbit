#include "..\include\Coin.h"

Coin::Coin(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setTextureRect(sf::IntRect(X, Y, XPOINT1, Y1));
	m_sprite.setScale(sf::Vector2f(0.1f, 0.1f));

	m_intRect.push_back(sf::IntRect(X, Y, XPOINT1, Y1));
	m_intRect.push_back(sf::IntRect(X + XPOINT1, Y, XPOINT1, Y1));
	m_intRect.push_back(sf::IntRect(X + XPOINT1 *2, Y, XPOINT1, Y1));
	m_intRect.push_back(sf::IntRect(X + XPOINT1 * 3, Y, XPOINT1, Y1));
	m_intRect.push_back(sf::IntRect(X + XPOINT1 * 4, Y, XPOINT1, Y1));
}

void Coin::update(sf::Time time)
{
	++m_textIndex;
	m_textIndex %= 5;
	m_sprite.setTextureRect(m_intRect[m_textIndex]);
}

void Coin::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Coin::handleCollision(Jazz& jazz)
{
	this->setDead(true);
	jazz.handleCollision(*this);
}

void Coin::handleCollision(Brick& brick)
{
}

void Coin::handleCollision(Carrot& carrot)
{
}

void Coin::handleCollision(Coin& coin)
{
}

void Coin::handleCollision(Ammo& ammo)
{
}

void Coin::handleCollision(Spike& Spike)
{
}

void Coin::handleCollision(Exit& exit)
{
}

void Coin::handleCollision(Turtle& turtle)
{
}



