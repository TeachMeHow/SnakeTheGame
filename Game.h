#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Thread.hpp>
#include "Board.h"

// Game class starts the game, shows results and tracks game scores
class Game
{
	sf::RenderWindow& window;
	int window_width, window_height;
	enum GameStates { START, IN_PROGRESS, END } state;
	Board board; 
	Snake snake;
public:
	Game(sf::RenderWindow& win);
	~Game();
	void start_game();
	void _debug_change_state(int i);
};

