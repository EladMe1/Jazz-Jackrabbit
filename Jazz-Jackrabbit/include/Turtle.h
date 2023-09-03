#pragma once

#include "MovingObject.h"
#include "Globals.h"
#include "Jazz.h"

class Turtle : public MovingObject{
public:
	Turtle();
	Turtle(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size, int level);
	void move(sf::Time time) override;
	void update(sf::Time time);
	void setDirection(const sf::Vector2f& pos);
	virtual void switchDir();

	virtual void handleCollision(GameObject& otherObject)override;
	virtual void handleCollision(Jazz& jazz)override;
	virtual void handleCollision(Brick& brick)override;
	virtual void handleCollision(Carrot& carrot)override;
	virtual void handleCollision(Coin& coin)override;
	virtual void handleCollision(Ammo& ammo) override;
	virtual void handleCollision(Spike& Spike)override;
	virtual void handleCollision(Exit& exit) override;
	virtual void handleCollision(Turtle& turtle)override;

private:
	int m_direction;
	std::map<int, std::vector<sf::IntRect>> m_map;
	sf::Time m_timePass = {};
	int m_textIndex = 0;
	float m_switchDirection;
	int m_level;
};