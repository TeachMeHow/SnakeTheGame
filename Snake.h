#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <chrono>
// Snake crawls on the board and eats things
// it gets longer when it eats
// Snake dies after it hits the wall
// When it dies, snake points is returned to measure the score
// Snake can have different speed

class Snake
{
	int points = 0;
	sf::Color color = sf::Color(149, 36, 0, 255);
	// % of base 
	double speed_multiplier = 6;
	enum Directions {UP, RIGHT, DOWN, LEFT } direction;
	std::list<sf::Vector2i> coordinates;
	std::chrono::time_point<std::chrono::steady_clock> time_buffer, time_buffer2;
	std::chrono::duration<double> base_interval;

public:
	Snake();
	~Snake();
	void draw(sf::RenderWindow& window);
	void operator++();
	bool has_snake(const sf::Vector2i coords);
	int get_points() { return points; }
	void move();
	bool collision();
	// 0 - go up
	// 1 - go right
	// 2 - go down
	// 3 - go left
	void steer(int dir);
	// update snake status - possibly every frame!
	// x, y is pos on grid
	// dir is the starting direction
	void set_start_point(int x, int y, int dir);
	sf::Vector2i head();
};

