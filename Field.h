#pragma once

// Snake moves over fields on the board
// if field has a thing on it, snake eats it
// if snake is on it and it hits it, snake dies
class Field
{
	bool apple;
public:
	Field();
	~Field();
	void set_apple() { apple = true; }
	void eat_apple() { apple = false; }
	bool has_apple() { return apple; }
};

