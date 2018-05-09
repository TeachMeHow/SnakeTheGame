#include "Game.h"
#include <iostream>
int main()
{
	std::chrono::duration<double> dur = std::chrono::seconds(1) / 2.1;
	std::cout << dur.count() << "s";
	sf::RenderWindow win;
	Game game = Game(win);
	game.start_game();
	return 0;
}