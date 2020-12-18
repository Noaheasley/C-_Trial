#include "Game.h"
#include <iostream>

void Game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();

		system("pause");
	}

	end();
}

void Game::start()
{
	Character* m_player1 = new Character(10, 10);
	Character* m_player2 = new Character(10, 10);
	system("pause");
}

void Game::update()
{
	std::cout << "Player1's turn" << std::endl;
	m_player1->attack(m_player2);
	m_player2->heal(m_player2);
}

void Game::draw()
{
	std::cout << "Player2 health is : " << m_player2->getHealth() << std::endl;
}

void Game::end()
{
	delete m_player1;
	delete m_player2;
}
