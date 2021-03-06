#include <iostream>
#include "game.hpp"

Game::Game(): m_window("Snake", sf::Vector2u(800, 600)),
	m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
	m_textbox.Setup(5, 14, 350, sf::Vector2f(255,0));
	m_textbox.Add("\t\t\t\t\t\t\t\tSFML-Snake");
	m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
	m_increment = sf::Vector2i(400,400);
}

Game::~Game() {}

void Game::Update()
{
	m_window.Update();

	float timestep = 1.0f / m_snake.GetSpeed();
	float fElapsed = m_elapsed.asSeconds();

	if (fElapsed >= timestep)
	{
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= sf::seconds(timestep);
		if (m_snake.HasLost())
		{
			m_snake.Reset();
		}
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	
	// Render here
	m_world.Render(m_window.GetRenderWindow());
	m_snake.Render(m_window.GetRenderWindow());
	m_textbox.Render(m_window.GetRenderWindow());

	m_window.EndDraw();
}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			&& m_snake.GetPhysicalDirection() != Direction::Down)	
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
			&& m_snake.GetPhysicalDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			&& m_snake.GetPhysicalDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			&& m_snake.GetPhysicalDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

Window* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
