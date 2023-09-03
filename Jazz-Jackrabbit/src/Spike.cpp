#include "..\include\Spike.h"

Spike::Spike(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setScale(sf::Vector2f(0.6f, 0.6f));
}

void Spike::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Spike::handleCollision(Jazz& jazz)
{
	jazz.handleCollision(*this);
}

void Spike::handleCollision(Brick& brick)
{
}

void Spike::handleCollision(Carrot& carrot)
{
}

void Spike::handleCollision(Coin& coin)
{
}

void Spike::handleCollision(Ammo& ammo)
{
}

void Spike::handleCollision(Spike& Spike)
{
}

void Spike::handleCollision(Exit& exit)
{
}

void Spike::handleCollision(Turtle& turtle)
{
}

