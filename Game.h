#pragma once
#include <SFML\Graphics.hpp>

// Game class starts the game, shows results and tracks game scores
class Game
{
	sf::RenderWindow window;
	int window_width, window_height;
	sf::ContextSettings window_settings;
public:
	Game();
	~Game();
};

