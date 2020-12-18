#include "Game.h"
#include <fstream>
#include <iostream>

std::fstream file;
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

	file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	if (!file.is_open())
	{
		return;
	}

	file << m_player1->getHealth() << std::endl;
	file << m_player1->getDamage() << std::endl;
	file << m_player2->getHealth() << std::endl;
	file << m_player2->getDamage();
	file.close();
	Character* m_player1 = new Character(m_player1->getHealth(), m_player1->getDamage());
	Character* m_player2 = new Character(m_player2->getHealth(), m_player2->getDamage());
	system("pause");
}

void Game::update()
{
	std::cout << "Player1's turn" << std::endl;
	m_player1->attack(m_player2);
	m_player2->heal(m_player2);

	file.open("save.txt", std::ios::in);
	if (!file.is_open())
	{
		return;
	}
	file >> m_player1->getHealth();
	file >> player2.damage;
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
