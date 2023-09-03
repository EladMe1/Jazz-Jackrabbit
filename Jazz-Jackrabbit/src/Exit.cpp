#include "..\include\Exit.h"

Exit::Exit(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:StaticObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(&texture);
	m_sprite.setScale(sf::Vector2f(0.4f, 0.4f));
}

void Exit::handleCollision(GameObject& otherObject)
{
}

void Exit::handleCollision(Jazz& jazz)
{
}

void Exit::handleCollision(Brick& brick)
{
}

void Exit::handleCollision(Carrot& carrot)
{
}

void Exit::handleCollision(Coin& coin)
{
}

void Exit::handleCollision(Ammo& ammo)
{
}

void Exit::handleCollision(Spike& Spike)
{
}

void Exit::handleCollision(Exit& exit)
{
}

void Exit::handleCollision(Turtle& turtle)
{
}

