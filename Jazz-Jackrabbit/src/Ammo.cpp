#include "..\include\Ammo.h"
#include <iostream>

const auto bulletSpeed = 1.2f;

Ammo::Ammo(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Ammo::movement()
{
	m_sprite.move(m_dir* bulletSpeed);
}


void Ammo::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Ammo::handleCollision(Jazz& jazz)
{
	this->setDead(true);
	jazz.handleCollision(*this);
}

void Ammo::handleCollision(Brick& brick)
{
}

void Ammo::handleCollision(Carrot& carrot)
{
}

void Ammo::handleCollision(Coin& coin)
{
}

void Ammo::handleCollision(Ammo& ammo)
{
}

void Ammo::handleCollision(Spike& Spike)
{
}

void Ammo::handleCollision(Exit& exit)
{
}

void Ammo::handleCollision(Turtle& turtle)
{
}



