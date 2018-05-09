#include "Game.h"



Game::Game(sf::RenderWindow& win) : window(win), board(snake)//, board()
{
	window_width = 600;
	// 600 for board + 200 for score
	window_height = 600 + 200;
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(window_width, window_height), "Snake", sf::Style::Titlebar | sf::Style::Close, window_settings);
	window.setFramerateLimit(60);
	
	snake.set_start_point(6, 6, 3);
	//sf::Thread game_thread(&Game::start_game, &window);
	//game_thread.launch();

}


Game::~Game()
{
}

void Game::start_game()
{
	window.setVisible(true);
	sf::Font font;
	// TODO check if font not loaded
	font.loadFromFile("font.ttf");
	state = IN_PROGRESS;
	while (state == IN_PROGRESS)
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				state = END;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				/*sf::Keyboard::Left;
				sf::Keyboard::Right;
				sf::Keyboard::Up;
				sf::Keyboard::Down;*/
				if (event.key.code == sf::Keyboard::Up)
					snake.steer(0);
				else if (event.key.code == sf::Keyboard::Right)
					snake.steer(1);
				else if (event.key.code == sf::Keyboard::Down)
					snake.steer(2);
				else if (event.key.code == sf::Keyboard::Left)
					snake.steer(3);
			}
		}
		board.update();
		board.draw(window, font);
		snake.draw(window);
		window.display();
	}
	window.close();
}

void Game::_debug_change_state(int i)
{
	switch (i)
	{
	case 0:
		state = START;
		break;
	case 1:
		state = IN_PROGRESS;
		break;
	case 2:
		state = END;
		break;
	default:
		break;
	}
}
