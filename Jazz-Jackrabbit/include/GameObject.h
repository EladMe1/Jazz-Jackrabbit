#pragma once

#include<SFML/Graphics.hpp>

class Jazz;
class Brick;
class Carrot;
class Coin;
class Ammo;
class Spike;
class Exit;
class Turtle;

class GameObject {
public:
	GameObject();
	GameObject(const sf::Texture& texture, const sf::Vector2f& pos,const sf::Vector2f& size);
	virtual ~GameObject();
	sf::FloatRect getGlobulBounds() const;
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	void draw(sf::RenderWindow& window);
	void setInitialPos(sf::Vector2f pos);
	void setDirection(const sf::Vector2f& pos);
	sf::Vector2f getDirection() const;

	virtual void handleCollision(GameObject& otherObject) = 0;
	virtual void handleCollision(Jazz& myJazz) = 0;
	virtual void handleCollision(Brick& myBrick) = 0;
	virtual void handleCollision(Carrot& carrot) = 0;
	virtual void handleCollision(Coin& coin) = 0;
	virtual void handleCollision(Ammo& ammo) = 0;
	virtual void handleCollision(Spike& Spike) = 0;
	virtual void handleCollision(Exit& exit) = 0;
	virtual void handleCollision(Turtle& turtle) = 0;

private:
	sf::Vector2f m_Currentpos;
	sf::Vector2f m_size;
	sf::Vector2f m_prevLoc;
protected:
	sf::RectangleShape m_sprite;
	sf::Vector2f m_dir;
};