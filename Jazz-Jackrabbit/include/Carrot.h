#pragma once

#include "StaticObject.h"
#include "Jazz.h"

class Carrot : public StaticObject{
public:
	Carrot(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	
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
};