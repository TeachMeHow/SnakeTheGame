#include "Game.h"
#include <fstream>
#include <iostream>



Game::Game(sf::RenderWindow& win) : window(win), board(snake)//, board()
{
	// open file and read scores
	std::ifstream file;
	file.open("scores.dat");
	int input;
	while (file >> input)
	{
		scores.push_back(input);
	}
	file.close();
	// sort scores
	std::sort(scores.begin(), scores.end(), [](int a, int b) { return a > b; });
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
	// open file and read scores
	std::ofstream file;
	file.open("scores.dat", std::ios::trunc);
	auto it = scores.cbegin();
	while (it != scores.cend())
	{
		file << *it << std::endl;
		it++;
	}
	file.close();
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
		snake.move();
		if (snake.collision())
			state = END;
		board.draw(window, font, scores);
		snake.draw(window);
		window.display();
	}
	// save scoreboard to file
	add_score(snake.get_points());
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

void Game::add_score(int score)
{
	scores.push_back(score);
	std::sort(scores.begin(), scores.end(), [](int a, int b) { return a > b; });
	if (scores.size() > 1000)
		scores.pop_back();
}
