#pragma once
#include "world.hpp"
#include "snake.hpp"
#include "textbox.hpp"
#include "window.hpp"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

	sf::Vector2i m_increment;

	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_window;

	World m_world;
	Snake m_snake;
	Textbox m_textbox;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};
