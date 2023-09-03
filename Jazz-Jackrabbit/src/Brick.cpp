#include "..\include\Brick.h"
#include <iostream>

Brick::Brick(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture,pos,size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Brick::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Brick::handleCollision(Jazz& jazz)
{
	jazz.handleCollision(*this);
}

void Brick::handleCollision(Brick& brick)
{
}

void Brick::handleCollision(Carrot& carrot)
{
}

void Brick::handleCollision(Coin& coin)
{
}

void Brick::handleCollision(Ammo& ammo)
{
}

void Brick::handleCollision(Spike& Spike)
{
}

void Brick::handleCollision(Exit& exit)
{
}

void Brick::handleCollision(Turtle& turtle)
{
}




