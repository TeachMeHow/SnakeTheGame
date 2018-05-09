#include "Snake.h"



Snake::Snake()
{
	time_buffer = std::chrono::steady_clock::now();
	time_buffer2 = std::chrono::steady_clock::now();
	// speed = distance / (time / multiplier) -> speed = multiplier * (distance / time)
	base_interval = std::chrono::seconds(1) / speed_multiplier;
}


Snake::~Snake()
{
}

void Snake::draw(sf::RenderWindow & window)
{
	sf::Color color = sf::Color(149, 36, 0, 255);
	sf::RectangleShape snake_tail;
	snake_tail.setFillColor(color);
	snake_tail.setSize(sf::Vector2f(27,27));
	// TODO fix
	auto dw = [&snake_tail, &window](const sf::Vector2i& c) 
	{ 
		snake_tail.setPosition(sf::Vector2f(30 + c.x * 27, 30 + c.y * 27)); 
		window.draw(snake_tail);
	};
	std::for_each(coordinates.cbegin(), coordinates.cend(), dw);
	
}

void Snake::operator++()
{ 
	++size;
	coordinates.push_back(coordinates.back());
}

bool Snake::has_snake(const sf::Vector2i coords)
{
	auto it = coordinates.cbegin();
	while (it != coordinates.cend());
	{
		if (*it == coords)
		{
			return true;
		}
		it++;
	}
	return false;
}


void Snake::move()
{
	std::chrono::time_point<std::chrono::steady_clock> t1 = std::chrono::steady_clock::now();
	std::chrono::duration<double> interval = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - time_buffer);
	if (interval > base_interval)
	{
		time_buffer = std::chrono::steady_clock::now();
		switch (direction)
		{
		case UP:
			coordinates.push_front(coordinates.front() + sf::Vector2i(0, -1));
			break;
		case RIGHT:
			coordinates.push_front(coordinates.front() + sf::Vector2i(1, 0));
			break;
		case LEFT:
			coordinates.push_front(coordinates.front() + sf::Vector2i(-1, 0));
			break;
		case DOWN:
			coordinates.push_front(coordinates.front() + sf::Vector2i(0, 1));
			break;
		}
		coordinates.pop_back();
	}
}

void Snake::steer(int dir)
{
	// TODO quick consequent keystrokes change direction
	switch (direction)
	{
	case UP:
	case DOWN:
		if (dir == 1)
			direction = RIGHT;
		else if (dir == 3)
			direction = LEFT;
		break;
	case RIGHT:
	case LEFT:
		if (dir == 0)
			direction = UP;
		else if (dir == 2)
			direction = DOWN;
		break;
	}
}


void Snake::set_start_point(int x, int y, int dir)
{

	switch (dir)
	{
	case 0:
		direction = UP;
		break;
	case 1:
		direction = RIGHT;
		break;
	case 2:
		direction = DOWN;
		break;
	case 3:
		direction = LEFT;
		break;
		// TODO arg error
	default: break;
	}
	coordinates.push_back(sf::Vector2i(x, y));
	coordinates.push_back(sf::Vector2i(x + 1, y));
	coordinates.push_back(sf::Vector2i(x + 2, y));
}
