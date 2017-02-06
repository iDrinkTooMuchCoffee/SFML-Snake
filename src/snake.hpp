#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

struct SnakeSegment{
 SnakeSegment(int x, int y) : position(x,y){}
 sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	// Helper methods
	void SetDirection(Direction l_dir);
	Direction GetPhysicalDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose();              // Handles losing
	void ToggleLost();

	void Extend();            // Grow the snake
	void Reset();             // Reset to starting position

	void Move();
	void Tick();              // Update method
	void Cut(int l_segments); // Method for cutting snake
	void Render(sf::RenderWindow& l_window);

private:
	void CheckCollision();

	SnakeContainer m_snakeBody;    // Segment vector
	int m_size;                    // size of the graphics
	Direction m_dir;               // current direction
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;                   // losing state
	sf::RectangleShape m_bodyRect; // Shape used in rendering
};
