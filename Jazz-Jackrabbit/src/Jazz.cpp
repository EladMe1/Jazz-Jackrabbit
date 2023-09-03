#include "Jazz.h"
#include <iostream>
using namespace std;


const auto jazSpeed = 2.5f;
const auto fallSpeed = 1.0f;
const auto JumpTime = sf::seconds(3);


Jazz::Jazz(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:MovingObject(texture, pos, size)
{
	m_sprite.setPosition(pos);
	m_sprite.setOrigin(m_sprite.getSize() / 2.f);
	m_sprite.setTexture(&texture);
	m_sprite.setTextureRect(sf::IntRect(MIDDLE, MIDDLEY, XPOINT, YPOINT));
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));

	m_fire = 1;
	m_score = 0;
	m_arsenal = 20;
	m_lives = 5;

	m_direction = DIRECTION::RIGHT;
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX * 2, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX * 3, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX * 4, MIDDLEY, XPOINT, YPOINT));

	m_map[WEAPONFIRE::WITHOUT][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 2, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 3, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 4, MIDDLEY, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 5, MIDDLEY, XPOINT, YPOINT));

	m_map[WEAPONFIRE::WITH][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX * 2, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::RIGHT].push_back(sf::IntRect(MIDDLE + ADDTOX * 3, 160, XPOINT, YPOINT));

	m_map[WEAPONFIRE::WITH][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 2, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 3, 160, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITH][DIRECTION::LEFT].push_back(sf::IntRect(MIDDLE - ADDTOX * 4, 160, XPOINT, YPOINT));

	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(430, 330, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(330, 630, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(MIDDLE + ADDTOX, 630, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(MIDDLE + ADDTOX * 1, 630, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(MIDDLE + ADDTOX * 2, 630, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(MIDDLE + ADDTOX * 3, 630, XPOINT, YPOINT));
	m_map[WEAPONFIRE::WITHOUT][DIRECTION::UP].push_back(sf::IntRect(MIDDLE + ADDTOX * 4, 630, XPOINT, YPOINT));
}

	int Jazz::getStatisic() const
{
	return m_score;
}

int Jazz::getArsenal() const
{
	return m_arsenal;
}


void Jazz::initialScore()
{

}

void Jazz::move(sf::Time time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = DIRECTION::LEFT;
		m_dir.x = -jazSpeed;
		m_sprite.move(m_dir);
		update(time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = DIRECTION::RIGHT;
		m_dir.x = jazSpeed;
		m_sprite.move(m_dir);
		update(time);
	}

	m_dir.x = 0;
	m_dir.y = 80.f*jazSpeed*time.asSeconds();
	m_sprite.move(m_dir);
	m_fire = 1;
}

void Jazz::update(sf::Time time)
{
	   ++m_textIndex;
		m_textIndex %= 5;
		m_sprite.setTextureRect(m_map[m_fire][m_direction].at(m_textIndex));	
}

void Jazz::updateJump(sf::Time time)
{
	++m_textIndex;
	m_textIndex %= 7;
	m_sprite.setTextureRect(m_map[m_fire][m_direction].at(m_textIndex));
}

void Jazz::resetMove()
{
	setDirection(-m_dir);
}

void Jazz::gravity(float delta)
{
	m_dir.y = fallSpeed;
	m_sprite.move(sf::Vector2f(m_dir.x, m_dir.y));
}

void Jazz::jump()
{
	sf::Time  time;
	if (m_isJumping)
	{
		m_isJumping = false;
		sf::Vector2f direction = m_dir;
		m_direction = DIRECTION::UP;

		while (m_dir.y > direction.y - 21.f)
		{
			m_dir.y -= 3.f;
			m_sprite.move(m_dir);
			update(time);
		}
	}	
		
}

void Jazz::updataLive(sf::Time time)
{
	static int counter = 1;
	static bool isEnter = true;
	static sf::Clock clock;

	if (int(clock.getElapsedTime().asSeconds()) > 5)
	{
		isEnter = true;
	}

	if (counter == 1)
	{
		clock.restart();
		counter++;
	}

	if (isEnter == true)
	{
		if (m_lives > 0)
			m_lives--;

		isEnter = false;
		clock.restart();
	}

}

void Jazz::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Jazz::handleCollision(Jazz& jazz)
{
}

void Jazz::handleCollision(Brick& brick)
{
		m_sprite.move(-m_dir);

		if (!m_isJumping)
			m_isJumping = true;
}

void Jazz::handleCollision(Carrot& carrot)
{	
	m_soundEffect.setBuffer(Resources::instance().getCarrotSound());
	m_soundEffect.play();
	m_soundEffect.setVolume(17);
	m_scoreCarrot++;
	m_countCarrot++;

	if (m_scoreCarrot == 5)
	{
		if(m_lives <=4)
			m_lives++;

		m_scoreCarrot = 0;
	}
		
}

void Jazz::handleCollision(Coin& coin)
{
	m_soundEffect.setBuffer(Resources::instance().getCoinsSound());
	m_soundEffect.play();
	m_soundEffect.setVolume(17);
	m_score += 50;
}

void Jazz::handleCollision(Ammo& ammo)
{
	m_arsenal++;
}

void Jazz::handleCollision(Spike& Spike)
{
	m_soundEffect.setBuffer(Resources::instance().getHurtSound());
	m_soundEffect.play();
	m_soundEffect.setVolume(17);
}

void Jazz::handleCollision(Exit& exit)
{
}

void Jazz::handleCollision(Turtle& turtle)
{
	m_soundEffect.setBuffer(Resources::instance().getHurtSound());
	m_soundEffect.play();
	m_soundEffect.setVolume(17);

	static int counter = 1;
	static bool isEnter = true;
	static sf::Clock clock;

	if (int(clock.getElapsedTime().asSeconds()) > 5)
	{
		isEnter = true;
	}

	if (counter == 1)
	{
		clock.restart();
		counter++;
	}

	if (isEnter == true)
	{
		if (m_lives > 0)
			m_lives--;

		isEnter = false;
		clock.restart();
	}
}


