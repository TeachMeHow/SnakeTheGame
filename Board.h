#pragma once
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
// Board is a user defined rectangular plane divided into fields
// each field can spawn an apple that can be eaten by a snake
// if snake hits the edge of a board, it dies

class Board
{
	// board style
	// color palette
	const sf::Color bg_color = sf::Color(109, 109, 109, 255);
	const sf::Color wall_color = sf::Color(41, 41, 41, 255);
	const sf::Color score_text_color = sf::Color(41, 41, 41, 255);
	const sf::Color	record_text_color = sf::Color(149, 36, 0, 255);
	const sf::Color field_color = sf::Color(77, 77, 77, 255);

	// number of fields vertical and horizontal
	int fields_x;
	int fields_y;
	// grid of fields
	std::vector<sf::Vector2i> coordinates;
	bool apple_placed = true;
	sf::Vector2i apple_coords = sf::Vector2i(1, 1);
	
	Snake& snake;
	// TODO make faster if there is a lot of SNEK
	void place_apple();


public:
	Board(Snake& sneck);
	~Board();
	// draws the background
	void draw(sf::RenderWindow& window, sf::Font& font) const;
	// update EVERY draw
	void update();
};

