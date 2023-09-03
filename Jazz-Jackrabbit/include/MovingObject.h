#pragma once

#include "GameObject.h"
#include "Globals.h"

class MovingObject : public GameObject{
public:
	MovingObject();
	MovingObject(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	virtual void move(sf::Time time) = 0;
	void turn();
	virtual void switchDir();
private:
	int m_direction;
};