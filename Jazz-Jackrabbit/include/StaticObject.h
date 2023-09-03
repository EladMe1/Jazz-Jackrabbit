#pragma once

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject();
	StaticObject(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	bool isDead() { return m_isDead; };
	void setDead(bool isDead) { m_isDead = isDead; };
private:
	bool m_isDead;
};