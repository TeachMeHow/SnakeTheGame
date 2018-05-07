#include "Game.h"



Game::Game()
{
	window_width = 1000;
	window_height = 1000;
	window_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(window_width, window_height), "Snake", sf::Style::Default, window_settings);
}


Game::~Game()
{
}
