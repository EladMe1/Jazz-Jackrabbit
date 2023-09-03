#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"

class Resources
{
public:
	~Resources();
	static Resources& instance();
	const sf::Font& getMenuFont() const;
	const sf::Texture& getMenuTexture() const;
	const sf::Texture& getJazzTexture() const;
	const sf::Texture& getLevelView(int level) const;
	const sf::Texture& getBrick() const;
	const sf::Texture& getEnemy(int level) const;
	const sf::Texture& getPresent1(int level) const;
	const sf::Texture& getPresent2(int level) const;
	const sf::Texture& getHeart() const;
	const sf::Texture& getFire() const;
	const sf::Texture& getSpike() const;
	const sf::Texture& getExit() const;
	const sf::Texture& getLoser() const;
	const sf::Texture& getLevelFinish() const;
	const sf::Texture& getWin() const;
	const sf::Texture& getX() const;
	const sf::SoundBuffer& getMenuSound() const;
	const sf::SoundBuffer& getOneShoot() const;
	const sf::SoundBuffer& getMultiShoot() const;
	const sf::SoundBuffer& getHurtSound() const;
	const sf::SoundBuffer& getCoinsSound() const;
	const sf::SoundBuffer& getCarrotSound() const;
	const sf::SoundBuffer& getClapSound() const;
	const sf::SoundBuffer& getGameOverSound() const;
private:
	Resources();
	Resources (const Resources&) = default;
	Resources& operator= (const Resources&) = default;
	void loadresources();
	void loadtextures();
	void loadfonts();
	void loadsounds();
	sf::Font m_font;
	std::vector<sf::Texture> m_textures;
	std::map<int, std::vector<sf::Texture>> m_map;
	std::vector<std::vector<sf::Texture>> m_presents;
	std::vector<sf::SoundBuffer> m_audios;
};