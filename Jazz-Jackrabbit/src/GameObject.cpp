#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:m_Currentpos(pos),m_size(size),m_prevLoc(pos)
{
	m_sprite.setTexture(&texture);
	m_sprite.setPosition(pos);
	m_sprite.setSize(sf::Vector2f(size.x/2, size.y/2));
	m_sprite.setOrigin(m_sprite.getSize().x / 2, m_sprite.getSize().y / 2);
}

GameObject::~GameObject()
{
}

sf::FloatRect GameObject::getGlobulBounds() const
{
	return m_sprite.getGlobalBounds();
}

const sf::Vector2f& GameObject::getPos() const
{
	return m_sprite.getPosition();
}

const sf::Vector2f& GameObject::getSize() const
{
	return m_size;
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void GameObject::setInitialPos(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);

	m_prevLoc = pos;
}

void GameObject::setDirection(const sf::Vector2f& dir)
{
	m_dir = dir;
}

sf::Vector2f GameObject::getDirection() const
{
	return m_dir;
}
