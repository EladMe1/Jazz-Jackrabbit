#include "Resources.h"


Resources::Resources()
{
	loadresources();
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

const sf::Font& Resources::getMenuFont() const
{
	return m_font;
}

const sf::Texture& Resources::getMenuTexture() const
{
	return m_textures[gametexture::MENU];
}

const sf::Texture& Resources::getJazzTexture() const
{
	return m_textures[gametexture::JAZZ];
}

const sf::Texture& Resources::getLevelView(int level) const
{
	return m_map.at(level).at(gametexture::LEVELVIEW);
}

const sf::Texture& Resources::getBrick() const
{
	return m_textures[gametexture::BRICK];
}

const sf::Texture& Resources::getEnemy(int level) const
{
	return m_map.at(level).at(gametexture::ENEMY);
}

const sf::Texture& Resources::getPresent1(int level) const
{
	return m_map.at(level).at(gametexture::PRESENT1);
}

const sf::Texture& Resources::getPresent2(int level) const
{
	return m_map.at(level).at(gametexture::PRESENT2);
}

const sf::Texture& Resources::getHeart() const
{
	return m_textures[gametexture::HEART];
}

const sf::Texture& Resources::getFire() const
{
	return m_textures[gametexture::FIRE];
}

const sf::Texture& Resources::getSpike() const
{
	return m_textures[gametexture::SPIKE];
}

const sf::Texture& Resources::getExit() const
{
	return m_textures[gametexture::EXITTEXTURE];
}

const sf::Texture& Resources::getLoser() const
{
	return m_textures[gametexture::LOSER];
}

const sf::Texture& Resources::getWin() const
{
	return m_textures[gametexture::WIN];
}

const sf::Texture& Resources::getX() const
{
	return m_textures[gametexture::XPIC];
}

const sf::Texture& Resources::getLevelFinish() const
{
	return m_textures[gametexture::FINISH];
}

const sf::SoundBuffer& Resources::getMenuSound() const
{
	return m_audios[SOUNDS::MENUSOUND];
}

const sf::SoundBuffer& Resources::getOneShoot() const
{
	return m_audios[SOUNDS::ONESHOOT];
}

const sf::SoundBuffer& Resources::getMultiShoot() const
{
	return m_audios[SOUNDS::MULTISHOOT];
}

const sf::SoundBuffer& Resources::getHurtSound() const
{
	return m_audios[SOUNDS::HURT];
}

const sf::SoundBuffer& Resources::getCoinsSound() const
{
	return m_audios[SOUNDS::COINSSOUND];
}

const sf::SoundBuffer& Resources::getCarrotSound() const
{
	return m_audios[SOUNDS::CARROTSOUND];
}

const sf::SoundBuffer& Resources::getClapSound() const
{
	return m_audios[SOUNDS::CLAP];
}

const sf::SoundBuffer& Resources::getGameOverSound() const
{
	return m_audios[SOUNDS::GAMEOVER];
}


void Resources::loadresources()
{
	loadtextures();
	loadfonts();
	loadsounds();
}

void Resources::loadtextures()
{
	int NUM_OF_PICTURES = 20;
	std::vector<sf::Texture> tex1;
	std::vector<sf::Texture> tex2;
	std::vector<sf::Texture> tex3;
	tex1.resize(NUM_OF_PICTURES);
	tex2.resize(NUM_OF_PICTURES);
	tex3.resize(NUM_OF_PICTURES);
	m_textures.resize(NUM_OF_PICTURES);

	m_textures[gametexture::MENU].loadFromFile("resources/menu.jpeg");
	m_textures[gametexture::JAZZ].loadFromFile("resources/j2.gif");
	
	tex1[gametexture::LEVELVIEW].loadFromFile("resources/level1.png");
	tex2[gametexture::LEVELVIEW].loadFromFile("resources/viewLevel2.png");
	tex3[gametexture::LEVELVIEW].loadFromFile("resources/level3.png");

	m_textures[gametexture::BRICK].loadFromFile("resources/brick.png");

	tex1[gametexture::ENEMY].loadFromFile("resources/turtle.gif");
	tex2[gametexture::ENEMY].loadFromFile("resources/turtle3.png");
	tex3[gametexture::ENEMY].loadFromFile("resources/enemy-turtle.gif");

	tex1[gametexture::PRESENT1].loadFromFile("resources/carrot.png");
	tex2[gametexture::PRESENT1].loadFromFile("resources/carrot.png");
	tex3[gametexture::PRESENT1].loadFromFile("resources/carrot.png");

	tex1[gametexture::PRESENT2].loadFromFile("resources/coin.png");
	tex2[gametexture::PRESENT2].loadFromFile("resources/coin.png");
	tex3[gametexture::PRESENT2].loadFromFile("resources/coin.png");
	
	m_textures[gametexture::HEART].loadFromFile("resources/heart-removebg-preview.png");
	m_textures[gametexture::FIRE].loadFromFile("resources/output-onlinepngtools.png");
	m_textures[gametexture::SPIKE].loadFromFile("resources/spike.png");
	m_textures[gametexture::EXITTEXTURE].loadFromFile("resources/exit.png");
	m_textures[gametexture::FINISH].loadFromFile("resources/levelFinish.jpeg");
	m_textures[gametexture::LOSER].loadFromFile("resources/lose.jpeg");
	m_textures[gametexture::WIN].loadFromFile("resources/winner.png");
	m_textures[gametexture::XPIC].loadFromFile("resources/x-removebg-preview.png");

	m_map.insert(std::make_pair(1, tex1));
	m_map.insert(std::make_pair(2, tex2));
	m_map.insert(std::make_pair(3, tex3));
}

void Resources::loadfonts()
{
	if (!m_font.loadFromFile("resources/SHOWG.TTF"))
	{
		std::perror("Couldn't load");
		exit(EXIT_FAILURE);
	}
}

void Resources::loadsounds()
{
	sf::SoundBuffer sound;
	sound.loadFromFile("resources/Menu-sound.wav");
	m_audios.push_back(sound);

   sound.loadFromFile("resources/oneShoot.wav");
   m_audios.push_back(sound);

   sound.loadFromFile("resources/Multishoot.wav");
   m_audios.push_back(sound);

   sound.loadFromFile("resources/hurt.wav");
   m_audios.push_back(sound);

   sound.loadFromFile("resources/coins.wav");
   m_audios.push_back(sound);

   sound.loadFromFile("resources/eating.wav");
   m_audios.push_back(sound);
	
   sound.loadFromFile("resources/claping.wav");
   m_audios.push_back(sound);

   sound.loadFromFile("resources/gameOver.wav");
   m_audios.push_back(sound);
}
