#include <iostream>
#include "Board.h"

Board::Board()
	:m_row(0),m_col(0),m_level(1)
{
	if (!openFile())
	{
		std::cout << "error"; // to do make a exccp
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 5; i++)
	{
		sf::RectangleShape heart;
		heart.setTexture(&Resources::instance().getHeart());
		heart.setSize(sf::Vector2f(20, 20));
		heart.setPosition(sf::Vector2f(0 + 20 * i, 0));
		m_hearts.emplace_back(heart);
	}

	sf::RectangleShape carrot;
	carrot.setTexture(&Resources::instance().getPresent1(1));
	carrot.setSize(sf::Vector2f(40, 40));
	carrot.setPosition(sf::Vector2f(667,-120));
	m_carrots.emplace_back(carrot);

	sf::RectangleShape x;
	x.setTexture(&Resources::instance().getX());
	x.setSize(sf::Vector2f(40,40));
	x.setPosition(sf::Vector2f(697,-120));
	m_carrots.emplace_back(x);

	m_carrotText.setFont(Resources::instance().getMenuFont());
	m_carrotText.setString("0");
	m_carrotText.setColor(sf::Color::White);
	m_carrotText.setCharacterSize(40);
	m_carrotText.setPosition(sf::Vector2f(737,-125));

	sf::RectangleShape coin;
	coin.setTexture(&Resources::instance().getPresent2(1));
	coin.setSize(sf::Vector2f(40, 40));
	coin.setPosition(sf::Vector2f(1500,-107));
	coin.setTextureRect(sf::IntRect(X, Y, XPOINT1, Y1));
	m_coins.emplace_back(coin);

	x.setPosition(sf::Vector2f(1530,-107));

	m_coins.emplace_back(x);

	m_coinText.setFont(Resources::instance().getMenuFont());
	m_coinText.setString("0");
	m_coinText.setColor(sf::Color::White);
	m_coinText.setCharacterSize(40);
	m_coinText.setPosition(sf::Vector2f(1593,-115));
}

Board::~Board()
{
	m_file.close();
}

bool Board::loadMatrix()
{
	if (m_file.eof())
		return false;

	m_file >> m_row;
	m_file >> m_col;
			
	         char c = m_file.get();

			std::string currentLine;

			for (int i = 0; i < m_row; i++)
			{
				std::getline(m_file, currentLine);
				m_matrix.push_back(currentLine);
			}

			return true;

}
bool Board::openFile()
{
	m_file.open(FILENAME);

	if (!m_file.is_open())
		return false;

	return true;
}

std::vector<std::string> Board::getLevel()
{
	return m_matrix;
}

void Board::loadLevel()
{

	char c;
	
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			c = chartoimage(m_matrix[i][j]);
			switch (c)
			{
			case JAZZCHAR:
				m_jazz = std::make_unique<Jazz>(Resources::instance().getJazzTexture(),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE));
				break;
			case BRICKCHAR:
				m_statics.push_back(std::make_unique<Brick>(Resources::instance().getBrick(),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE)));
				break;
			case SPIKECHAR:
				m_statics.push_back(std::make_unique<Spike>(Resources::instance().getSpike(),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE)));
				break;
			case TURTLECHAR:
					m_enemies.push_back(std::make_unique<Turtle>(Resources::instance().getEnemy(m_level),
						sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE),m_level));
				break;
			case CARROTCHAR:
				m_presents.push_back(std::make_unique<Carrot>(Resources::instance().getPresent1(m_level),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE)));
				break;
			case COINCHAR:
				m_presents.push_back(std::make_unique<Coin>(Resources::instance().getPresent2(m_level),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE)));
				break;
			case AMMOCHAR:
				m_ammos.push_back(std::make_unique<Ammo>(Resources::instance().getFire(),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE)));
				break;
			case EXITCHAR:
				m_exit = std::make_unique<Exit>(Resources::instance().getExit(),
					sf::Vector2f(j * DISTANCE2, i * DISTANCE2), sf::Vector2f(SIZE, SIZE));
				break;
			case BLOCKERCHAR:
			{
				sf::RectangleShape r;
				r.setFillColor(sf::Color::Transparent);
				r.setSize(sf::Vector2f(10, 10));
				r.setPosition(sf::Vector2f(j * DISTANCE2, i * DISTANCE2));
				m_blockers.push_back(r);
				break;
			}
			default:
				break;
			}
		}
	}

	

}

void Board::handleEvent(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Space:
		fire();
		break;
	case sf::Keyboard::Up:
		m_jazz->jump();
		break;
	case sf::Keyboard::P:
		createPuase();
		break;
	default:
		break;
	}
}

void Board::handleCollisions(sf::Time delta)
{

	for (auto& enemy : m_enemies) 
	{
		if (m_jazz->getGlobulBounds().intersects(enemy->getGlobulBounds()))
		{
			m_jazz->handleCollision(*enemy);
		}
	}
	
	for (size_t i = 0; i < m_presents.size(); i++)
	{
		if (m_jazz->getGlobulBounds().intersects(m_presents[i]->getGlobulBounds()))
		{
			m_jazz->handleCollision(*m_presents[i]);

			if (m_presents[i]->isDead())
			{
				m_presents.erase(m_presents.begin() + i);
			}
		}
	}

	for (size_t i = 0; i < m_statics.size(); i++)
	{
		if (m_jazz->getGlobulBounds().intersects(m_statics[i]->getGlobulBounds()))
		{
			m_jazz->handleCollision(*m_statics[i]);

			if (dynamic_cast<Spike*>(m_statics[i].get()))
			{
				m_jazz->updataLive(delta);
			}
		}
	}

	for (size_t i = 0; i < m_blockers.size(); i++)
	{
		for (size_t j = 0; j < m_enemies.size(); j++)
		{
			if (m_blockers[i].getGlobalBounds().intersects(m_enemies[j]->getGlobulBounds()))
			{
				m_enemies[j]->turn();
				m_enemies[j]->switchDir();
			}
		}
	}

	for (size_t i = 0; i < m_ammos.size(); i++)
	{
		if (m_jazz->getGlobulBounds().intersects(m_ammos[i]->getGlobulBounds()))
		{
			m_jazz->handleCollision(*m_ammos[i]);

			if (m_ammos[i]->isDead())
			{
				m_ammos.erase(m_ammos.begin() + i);
			}
		}
	}

	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		for (size_t j = 0; j < m_enemies.size(); j++)
		{
			if (m_bullets[i]->getGlobulBounds().intersects(m_enemies[j]->getGlobulBounds()))
			{
				m_bullets.erase(m_bullets.begin() + i);
				m_enemies.erase(m_enemies.begin() + j);
				break;
			}
		}
	}


}

void Board::moveObjects(sf::Time time)
{
	m_jazz->move(time);
	for (auto& enemy : m_enemies)
	{
		enemy->move(time);
	}
	
	for (auto& bullet: m_bullets)
	{
		bullet->movement();
	}
}

void Board::draw(sf::RenderWindow& gameWindow)
{
	m_jazz->draw(gameWindow);
	for (auto& enemy : m_enemies) {
		enemy->draw(gameWindow);
	}
	for (auto& present : m_presents) {
		present->draw(gameWindow);
	}
	for (auto& static_obj : m_statics) {
		static_obj->draw(gameWindow);
	}
	for (auto& ammo : m_ammos) {
		ammo->draw(gameWindow);
	}
	
	for (auto& bullet : m_bullets)
	{
		bullet->draw(gameWindow);
	}

	m_exit->draw(gameWindow);
	
	for (int i = 0; i < m_jazz->getlives(); i++)
	{
		m_hearts[i].setPosition(m_jazz->getPos().x + 20 * i - 50, m_jazz->getPos().y - 50);
		gameWindow.draw(m_hearts[i]);
	}

	for (size_t i = 0; i < m_carrots.size(); i++)
	{
		m_carrots[i].setPosition(m_jazz->getPos().x + 30 * i -455,m_jazz->getPos().y - 417);
		gameWindow.draw(m_carrots[i]);
	}
	m_carrotText.setString(std::to_string(m_jazz->getCountCarrot()));
	m_carrotText.setPosition(m_carrots[m_carrots.size() - 1].getPosition().x + 30,
		                     m_carrots[m_carrots.size() - 1].getPosition().y);
	gameWindow.draw(m_carrotText);

	for (size_t i = 0; i < m_coins.size(); i++)
	{
		m_coins[i].setPosition(m_jazz->getPos().x + 30 * i + 401, m_jazz->getPos().y - 402);
		gameWindow.draw(m_coins[i]);
	}
	m_coinText.setString(std::to_string(m_jazz->getStatisic()));
	m_coinText.setPosition(m_coins[m_coins.size() - 1].getPosition().x + 30,
		                   m_coins[m_coins.size() - 1].getPosition().y - 10);
	gameWindow.draw(m_coinText);
}

const sf::Vector2f& Board::getJazzPos() const
{
	return m_jazz->getPos();
}

void Board::fire()
{
	m_soundEffect.setBuffer(Resources::instance().getOneShoot());
	m_soundEffect.play();
	m_soundEffect.setVolume(17);
	m_bullets.emplace_back(std::make_unique<Ammo>(Resources::instance().getFire(),
		                                           m_jazz->getPos(), sf::Vector2f(SIZE, SIZE)));
	
	if (m_jazz->getAnimationDirection() == DIRECTION::RIGHT)
	{
		m_bullets[m_bullets.size()-1]->setDirection(sf::Vector2f(1,0));
	}
	else if (m_jazz->getAnimationDirection() == DIRECTION::LEFT)
	{
		m_bullets[m_bullets.size() - 1]->setDirection(sf::Vector2f(-1,0));
	}
}

void Board::createPuase()
{
	sf::RenderWindow window(sf::VideoMode(Window_WIDTH - 200, Window_HEIGHT - 70), "Game - Jazz Jackrabbit - Pause");

	sf::Text text;
	text.setFont(Resources::instance().getMenuFont());
	text.setString("Continue");
	text.setColor(sf::Color::White);
	text.setCharacterSize(50);
	text.setPosition(sf::Vector2f(250, 300));
	m_pauseButton.push_back(text);

	text.setString("Menu");
	text.setPosition(sf::Vector2f(250, 300 + 100));
	m_pauseButton.push_back(text);

	auto background = sf::Texture();
	background.loadFromFile("resources/menu.jpeg");

	auto sprite_B = sf::Sprite(background);

	int index = 0;

	sf::Vector2f loc;

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		window.draw(sprite_B);
		for (auto i = 0; i < m_pauseButton.size(); i++)
		{
			window.draw(m_pauseButton[i]);
		}
		window.display();
		auto event = sf::Event(); //now get from keyboard inforamtion

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			switch (event.type)
			{
			case sf::Event::MouseButtonReleased:
				loc = window.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
				if (handleClick(loc, index))
				{
					handlePressEnter(window, index);
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
					handlePressEnter(window, index);
					break;
				case sf::Keyboard::Up:
					index--;
					break;
				case sf::Keyboard::Down:
					index++;
					break;
				default:
					break;
				}
				index = index % m_pauseButton.size();
			default:
				break;
			}
		}
	}
}

void Board::handlePressEnter(sf::RenderWindow& window, int& index)
{
	switch (index)
	{
	case 0:
		window.close();
		break;
	case 1:
		window.close();
		//m_gameWindow.close();
		break;

	}
}

bool Board::handleClick(const sf::Vector2f& location, int& index)
{
	if (m_pauseButton[0].getGlobalBounds().contains(location))
	{
		index = 0;
		return true;
	}
	if (m_pauseButton[1].getGlobalBounds().contains(location))
	{
		index = 1;
		return true;
	}
	return false;
}

bool Board::isLevelComlete()
{
	if (m_jazz->getGlobulBounds().intersects(m_exit->getGlobulBounds()))
	{
		return true;
	}

	return false;
}

void Board::clear()
{
	m_ammos.clear();
	m_blockers.clear();
	m_bullets.clear();
	m_enemies.clear();
}

bool Board::lose()
{
	if (m_jazz->getlives() <= 0)
		return true;

	return false;
}

	
