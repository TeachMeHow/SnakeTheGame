#include "Board.h"



Board::Board(Snake& sneck) : snake(sneck)
{
	fields_x = 15;
	fields_y = 15;
}


Board::~Board()
{
}

void Board::draw(sf::RenderWindow & window, sf::Font& font) const
{
	
	window.clear(bg_color);
	int window_width = window.getSize().x;
	int frame_size = window_width - 2 * 20;
	int padding_y = 20;
	int padding_x = 20;

	sf::RectangleShape frame;
	frame.setSize(sf::Vector2f(frame_size, frame_size));
	frame.setFillColor(wall_color);
	frame.setPosition(padding_x, padding_y);

	int foreground_padding = 10;
	int foreground_size = frame_size - foreground_padding * 2;
	sf::RectangleShape foreground;
	foreground.setSize(sf::Vector2f(foreground_size, foreground_size));
	foreground.setFillColor(bg_color);
	foreground.setPosition(frame.getPosition() + sf::Vector2f(foreground_padding, foreground_padding));
	
	sf::RectangleShape board_field;
	board_field.setFillColor(field_color);
	double field_size;
	field_size = foreground.getSize().x / fields_x;
	board_field.setSize(sf::Vector2f(field_size, field_size));

	sf::Text score;
	score.setFont(font);
	score.setFillColor(score_text_color);
	int score_font_size = 36;
	score.setCharacterSize(score_font_size);
	score.setPosition(sf::Vector2f(20, 600 + 100));
	score.setString("Score: 123");

	sf::Text best_score;
	best_score.setFont(font);
	best_score.setFillColor(record_text_color);
	int best_font_size = 48;
	best_score.setCharacterSize(best_font_size);
	sf::Vector2f best_score_pos;
	best_score_pos.x = window.getSize().x / 2;
	best_score_pos.y = 600 + 100 - (best_font_size - score_font_size);
	best_score.setPosition(best_score_pos);
	best_score.setString("BEST SCORE: 200");


	window.draw(frame);
	window.draw(foreground);
	for (size_t j = 0; j < fields_y; j++)
	{
		for (size_t i = 0; i < fields_x; i++)
		{
			if (i % 2 == j % 2)
			{
				board_field.setPosition(foreground.getPosition() + sf::Vector2f(i * field_size, j * field_size));
				window.draw(board_field);
			}
		}
	}
	window.draw(score);
	window.draw(best_score);
}
