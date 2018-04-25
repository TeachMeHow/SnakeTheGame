#pragma once

// Board is a user defined rectangular plane divided into fields
// each field can spawn an apple that can be eaten by a snake
// if snake hits the edge of a board, it dies

class Board
{
	// in px
	int fields_x;
	int fields_y;
public:
	Board();
	~Board();
};

