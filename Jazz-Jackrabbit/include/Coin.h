#pragma once

#include "StaticObject.h"
#include "Jazz.h"

class Coin : public StaticObject {
public:
	Coin(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	virtual void update(sf::Time time);

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
	std::vector<sf::IntRect> m_intRect;
	int m_textIndex = 0;
};