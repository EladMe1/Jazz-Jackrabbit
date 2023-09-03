#include "..\include\Carrot.h"

Carrot::Carrot(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Carrot::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Carrot::handleCollision(Jazz& jazz)
{
	this->setDead(true);
	jazz.handleCollision(*this);
}

void Carrot::handleCollision(Brick& brick)
{
}

void Carrot::handleCollision(Carrot& carrot)
{
}

void Carrot::handleCollision(Coin& coin)
{
}

void Carrot::handleCollision(Ammo& ammo)
{
}

void Carrot::handleCollision(Spike& Spike)
{
}

void Carrot::handleCollision(Exit& exit)
{
}

void Carrot::handleCollision(Turtle& turtle)
{
}


