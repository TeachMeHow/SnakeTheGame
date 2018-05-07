#pragma once
#include "Field.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
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
	// number of fields vertical and horizontal
	int fields_x;
	int fields_y;
	int size_x;
	int size_y;
	// grid of fields
	Field** grid;

public:
	Board();
	~Board();
	void draw(sf::RenderWindow& window) const;
};

