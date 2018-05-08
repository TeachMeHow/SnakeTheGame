#include "Game.h"
int main()
{
	sf::RenderWindow win;
	Game game = Game(win);
	game.start_game();
	return 0;
}