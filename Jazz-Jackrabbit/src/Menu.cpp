#include "Menu.h"

Menu::Menu()
	:m_width(0), m_height(0)
{
}

Menu::Menu(const float& width, const float& height)
	:m_width(width),m_height(height)
{
	m_choseIndex = 0;
	m_menuButtons.resize(NUM_OF_BUTTONS);
	createMenu();
	createWindow();
}

Menu::~Menu()
{
}

void Menu::run()
{
	playMusic();

	while (m_menuWindow.isOpen())
	{
		handleMenuEvents();
		draw();
	}
}

void Menu::draw()
{
	m_menuWindow.clear();
	drawMenuBg();
	drawMenuButton();
	m_menuWindow.display();
}

void Menu::createMenu()
{
	m_menuButtons[0].setFont(Resources::instance().getMenuFont());
	m_menuButtons[0].setString("NEW GAME");
	m_menuButtons[0].setFillColor(sf::Color::Red);
	m_menuButtons[0].setPosition(m_width / 2, m_height / 2 - DISTANCE * 1);
	m_menuButtons[0].setScale(sf::Vector2f(1,1));

	m_menuButtons[1].setFont(Resources::instance().getMenuFont());
	m_menuButtons[1].setString("INFORMATION");
	m_menuButtons[1].setFillColor(sf::Color::Green);
	m_menuButtons[1].setPosition(m_width / 2, m_height / 2 - DISTANCE * 2);
	m_menuButtons[1].setScale(sf::Vector2f(1, 1));

	m_menuButtons[2].setFont(Resources::instance().getMenuFont());
	m_menuButtons[2].setString("FULL SCREEN");
	m_menuButtons[2].setFillColor(sf::Color::Green);
	m_menuButtons[2].setPosition(m_width / 2, m_height / 2 - DISTANCE * 3);
	m_menuButtons[2].setScale(sf::Vector2f(1, 1));

	m_menuButtons[3].setFont(Resources::instance().getMenuFont());
	m_menuButtons[3].setString("SOUND");
	m_menuButtons[3].setFillColor(sf::Color::Green);
	m_menuButtons[3].setPosition(m_width / 2, m_height / 2 - DISTANCE * 4);
	m_menuButtons[3].setScale(sf::Vector2f(1, 1));

	m_menuButtons[4].setFont(Resources::instance().getMenuFont());
	m_menuButtons[4].setString("EXIT");
	m_menuButtons[4].setFillColor(sf::Color::Green);
	m_menuButtons[4].setPosition(m_width / 2, m_height / 2 - DISTANCE * 5);
	m_menuButtons[4].setScale(sf::Vector2f(1, 1));
}

void Menu::drawMenuBg()
{
	auto texture = Resources::instance().getMenuTexture();
	auto background = sf::Sprite(texture);
	m_menuWindow.draw(background);
}

void Menu::drawMenuButton()
{
	for (auto& button :m_menuButtons)
	{
		m_menuWindow.draw(button);
	}
}

void Menu::handleMenuEvents()
{
	sf::Event event;
	while (m_menuWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_menuWindow.close();
			break;
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Enter:
				handlePressEnter(m_choseIndex);
				break;
			case sf::Keyboard::Up:
				m_choseIndex--;
				break;
			case sf::Keyboard::Down:
				m_choseIndex++;
				break;
			default:
				break;
			}
			m_choseIndex = m_choseIndex % m_menuButtons.size();
			showChoice(m_choseIndex);
		default:
				break;	
		}
	}
}

void Menu::showChoice(int& index)
{
	for (int i = 0; i < m_menuButtons.size(); i++)
	{
		if (i == index)
		{
			m_menuButtons[i].setFillColor(sf::Color::Red);
		}
		else
		{
			m_menuButtons[i].setFillColor(sf::Color::Green);
		}
	}
}

void Menu::handlePressEnter(int& index)
{
	switch (index)
	{
	case STARTGAME:
	{
		Controller game;
		game.run();
		break;
	}
		
	case INFORMATION:
		createHelp();
		break;
	case FULLSCRREN:
		m_menuWindow.setSize(sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height));
		break;
	case SOUND:
		if (m_sound.getStatus() == sf::SoundSource::Status::Playing)
		{
			m_sound.stop();
			m_menuButtons[SOUND].setString("SOUND ON");
		}
		else
		{
			m_sound.play();
			m_menuButtons[SOUND].setString("SOUND OFF");
		}
		break;
	case EXIT:
		m_menuWindow.close();
		break;
	}
}

void Menu::playMusic()
{
	m_sound.setBuffer(Resources::instance().getMenuSound());
	m_sound.play();
	m_sound.setVolume(10);
}

void Menu::createHelp()
{
	sf::RenderWindow windowHelp;

	windowHelp.create(sf::VideoMode(1600, 740), "Jazz Jackrabbit - Help");

	auto background = sf::Texture();
	background.loadFromFile("resources/info.jpeg");

	auto sprite_B = sf::Sprite(background);

	while (windowHelp.isOpen())
	{
		windowHelp.clear(sf::Color::White);
		windowHelp.draw(sprite_B);
		windowHelp.display();

		auto event = sf::Event(); //now get from keyboard inforamtion

		while (windowHelp.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				windowHelp.close();
			}

		}

	}
}

void Menu::createWindow()
{
	m_menuWindow.create(sf::VideoMode(m_width,m_height),"Menu - Jazz Jackrabbit");
}
