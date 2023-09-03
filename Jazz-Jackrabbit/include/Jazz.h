#pragma once

#include "MovingObject.h"
#include "Direction.h"
#include "Globals.h"
#include "Brick.h"
#include "Carrot.h"
#include "Ammo.h"
#include "Resources.h"

const auto JazzPicLoadTime = sf::seconds(3.0f);
const auto DcreaseLifeTime = sf::seconds(2.0f);

class Jazz : public MovingObject {
public:
	Jazz(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	int getStatisic() const;
	int getArsenal() const;
	void initialScore();
	void move(sf::Time time) override;
	void update(sf::Time time);
	void updateJump(sf::Time time);
	void resetMove();
	void gravity(float delta);
	void jump();
	void updataLive(sf::Time time);

	virtual void handleCollision(GameObject& otherObject)override;
	virtual void handleCollision(Jazz& jazz)override;
	virtual void handleCollision(Brick& brick)override;
	virtual void handleCollision(Carrot& carrot)override;
	virtual void handleCollision(Coin& coin)override;
	virtual void handleCollision(Ammo& ammo) override;
	virtual void handleCollision(Spike& Spike)override;
	virtual void handleCollision(Exit& exit) override;
	virtual void handleCollision(Turtle& turtle)override;
	int getAnimationDirection() const { return m_direction; };
	void setJump(bool jump) { m_isJumping = jump; };
	int getlives() const { return m_lives; } ;
	int getCountCarrot() const { return m_countCarrot; };
	
private:
	int m_fire;
	int m_direction;
	std::map<int, std::map<int, std::vector<sf::IntRect>>> m_map;
	sf::Time m_timePass = {};
	sf::Time m_elpas = {};
	int m_textIndex = 0;
	int m_score;
	int m_arsenal;
	int m_lives;
	bool m_isJumping = true;
	sf::Sound m_soundEffect;
	int m_scoreCarrot = 0;
	int m_countCarrot = 0;
};