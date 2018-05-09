#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include <chrono>
// Snake crawls on the board and eats things
// it gets longer when it eats
// Snake dies after it hits the wall
// When it dies, snake size is returned to measure the score
// Snake can have different speed

class Snake
{
	int size = 0;
	// % of base 
	double speed_multiplier = 3;
	enum Directions {UP, RIGHT, DOWN, LEFT } direction;
	std::list<sf::Vector2i> coordinates;
	std::chrono::time_point<std::chrono::steady_clock> time_buffer, time_buffer2;
	std::chrono::duration<double> base_interval;

public:
	Snake();
	~Snake();
	void draw(sf::RenderWindow& window);
	void operator++();
	int get_size() { return size; }
	void move();
	// 0 - go up
	// 1 - go right
	// 2 - go down
	// 3 - go left
	void steer(int dir);
	// update snake status - possibly every frame!
	// x, y is pos on grid
	// dir is the starting direction
	void set_start_point(int x, int y, int dir);
};

