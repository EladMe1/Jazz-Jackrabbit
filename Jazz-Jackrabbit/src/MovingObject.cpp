#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject()
{
}

MovingObject::MovingObject(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:GameObject(texture,pos,size)
{
}

void MovingObject::turn()
{
	m_dir.x = -m_dir.x;

	if (m_dir.x == 1)
	{
		m_direction == DIRECTION::RIGHT;
	}
		
	else
	{
		m_direction == DIRECTION::LEFT;
	}
}

void MovingObject::switchDir()
{
	if (m_direction == DIRECTION::RIGHT)
	{
		m_direction = DIRECTION::LEFT;
		return;
	}

	else if (m_direction == DIRECTION::LEFT)
	{
		m_direction == DIRECTION::RIGHT;
		return;
	}
		
}
