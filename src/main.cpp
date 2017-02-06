#include "game.hpp"

int main(int argc, char** argv)
{
	// Program entry point
	Game game; // create game object
	while (!game.GetWindow()->IsDone())
	{
		// Game loop
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock(); // Restart the clock
	}

	return 0;
}
