#include "..\include\Controller.h"

Controller::Controller()
	:m_level(1)
{
	createWindow();
	sf::View view(sf::FloatRect(0.f,0.f,Window_WIDTH,Window_HEIGHT));

	m_bg.setSize({ Window_WIDTH + Window_WIDTH*2,Window_HEIGHT + Window_HEIGHT *2});
	m_bg.setTextureRect(sf::IntRect(XV,YV, WV, HV));
	m_bg.setPosition(0, 0);
	m_bg.setTexture(&Resources::instance().getLevelView(m_level));
}

Controller::~Controller()
{

}

void Controller::run()
{
	while (m_board.loadMatrix() && m_board.getMlevel() < (LEVEL3 + 1))
	{	
		m_board.loadLevel();
		
		m_timer = m_gameClock.restart();

		auto clock = sf::Clock();

			while (m_gameWindow.isOpen())
			{
				handleEvent();
				auto delta = clock.restart();
				handleCollision(delta);
				draw();

				chekIfLose();

				if (levelComplete())
				{
					m_board.clear();
					m_board.addLevel();
					if(m_board.getMlevel() <= LEVEL3)
						nextLevel();
					break;
				}
	
			}
	}

	if(m_board.getMlevel() > LEVEL3)
		endGame();
}

void Controller::createWindow()
{
	m_gameWindow.create(sf::VideoMode(Window_WIDTH,Window_HEIGHT), "Game - Jazz Jackrabbit");
}

void Controller::handleEvent()
{
	m_timer = m_gameClock.restart();

	sf::Event event;
	while (m_gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_gameWindow.close();
			break;
		case sf::Event::KeyPressed:
			m_board.handleEvent(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
		{
			auto location = m_gameWindow.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
			std::cout << location.x << " " << location.y << "\n";
			auto loc = m_board.getJazzPos();
			std::cout << loc.x << " " << loc.y << "\n";
			break;
		}
		default:
			break;
		}
	}

	m_gameView.setCenter(m_board.getJazzPos());
	m_board.moveObjects(m_timer);
}

void Controller::draw()
{
	int level = m_board.getMlevel();
	m_gameWindow.clear();
	m_bg.setTexture(&Resources::instance().getLevelView(level));
	m_gameWindow.setView(m_gameView);

	sf::Vector2f pos = m_board.getJazzPos();
	
	if (pos.x <= 477)
		pos.x = 477;
	if (pos.y < 650)
		pos.y = 650;
	m_gameView.setCenter(pos);
	m_gameWindow.draw(m_bg);
	m_board.draw(m_gameWindow);
	m_gameWindow.display();
}


void Controller::handleCollision(sf::Time delta)
{
	m_board.handleCollisions(delta);
}

bool Controller::levelComplete()
{
	return m_board.isLevelComlete();
}

void Controller::nextLevel()
{
	sf::RenderWindow GameWindow;
	GameWindow.create(sf::VideoMode(500, 500), "Jazz jackrabbit - nextLevel");

	std::vector<sf::Text> text;

	sf::Text text1;

	text1.setFont(Resources::instance().getMenuFont());
	text1.setColor(sf::Color::White);
	text1.setString("next level");
	text1.setCharacterSize(50);
	text1.setPosition(sf::Vector2f(70, 100 + 50 * 4));
	text.push_back(text1);

	m_soundEffect.setBuffer(Resources::instance().getClapSound());
	m_soundEffect.play();

	auto next = sf::Texture();
	next = Resources::instance().getLevelFinish();

	auto sprite_N = sf::Sprite(next);

	while (GameWindow.isOpen())
	{
		GameWindow.clear(sf::Color::White);
		GameWindow.draw(sprite_N);

		for (int i = 0; i < text.size(); i++)
		{
			GameWindow.draw(text[i]);
		}

		auto event = sf::Event();

		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				GameWindow.close();
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				auto location = GameWindow.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
				if (text[0].getGlobalBounds().contains(location))
				{
					return;
				}
			}

		}
		GameWindow.display();
	}
}

void Controller::endGame()
{
	sf::RenderWindow GameWindow;
	GameWindow.create(sf::VideoMode( 1362, 1404), "Jazz Jackrabbit - win");

	std::vector<sf::Text> text;

	sf::Text text1;

	text1.setFont(Resources::instance().getMenuFont());
	text1.setColor(sf::Color::White);
	text1.setString("Click here to move to Menu");
	text1.setCharacterSize(50);
	text1.setPosition(sf::Vector2f(100, 100 + 50 * 5));
	text.push_back(text1);

	m_soundEffect.setBuffer(Resources::instance().getClapSound());
	m_soundEffect.play();

	auto next = sf::Texture();
	next = Resources::instance().getWin();

	auto sprite_N = sf::Sprite(next);

	while (GameWindow.isOpen())
	{
		GameWindow.clear(sf::Color::White);
		GameWindow.draw(sprite_N);

		for (int i = 0; i < text.size(); i++)
		{
			GameWindow.draw(text[i]);
		}

		auto event = sf::Event();

		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				GameWindow.close();
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				auto location = GameWindow.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
				if (text[0].getGlobalBounds().contains(location))
				{
					return;
				}
			}

		}
		GameWindow.display();
	}
}

void Controller::chekIfLose()
{
	if (m_board.lose())
	{
		sf::RenderWindow GameWindow;
		GameWindow.create(sf::VideoMode(1600, 900), "Jazz jackrabbit - Lose");

		std::vector<sf::Text> text;

		sf::Text text1;

		text1.setFont(Resources::instance().getMenuFont());
		text1.setColor(sf::Color::White);
		text1.setString("Menu");
		text1.setCharacterSize(60);
		text1.setPosition(sf::Vector2f(1266, 429));
		text.push_back(text1);

		m_soundEffect.setBuffer(Resources::instance().getGameOverSound());
		m_soundEffect.play();

		auto next = sf::Texture();
		next = Resources::instance().getLoser();

		auto sprite_N = sf::Sprite(next);

		while (GameWindow.isOpen())
		{
			GameWindow.clear(sf::Color::White);
			GameWindow.draw(sprite_N);

			for (int i = 0; i < text.size(); i++)
			{
				GameWindow.draw(text[i]);
			}

			auto event = sf::Event();

			while (GameWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					GameWindow.close();
				}

				if (event.type == sf::Event::MouseButtonReleased)
				{
					auto location = GameWindow.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
					//std::cout << location.x << " " << location.y << "\n";
					if (text[0].getGlobalBounds().contains(location))
					{
						GameWindow.close();
						m_gameWindow.close();
					}
				}

			}
			GameWindow.display();
		}
	}
}




