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
	int num = 0;
	while (num != 1 || num != 2)
	{
		std::cout << "Welcome to the arena, do you wish to start a new game or return to an old game?" << std::endl;
		std::cout << "1. New Game" << std::endl;
		std::cout << "2. Load a Game" << std::endl;
		std::cin >> num;
		if (num == 1)
		{
			m_player1 = new Character(100, 10);
			m_player2 = new Character(100, 10);
			break;
		}
		else if (num == 2)
		{
			Character* player1;
			Character* player2;
			file.open("saveBin.txt", std::ios::in | std::ios::binary);

			file.seekg(sizeof(Character), std::ios::beg);

			file.read((char*)&player1, sizeof(Character));

			std::cout << player1->getHealth() << std::endl;
			std::cout << player1->getDamage() << std::endl;

			/*file.seekg(sizeof(Character) * 1, std::ios::beg);

			file.read((char*)&player2, sizeof(Character));

			std::cout << player2->getHealth() << std::endl;
			std::cout << player2->getDamage() << std::endl;*/
			file.close();

			m_player1->setHealth(player1->getHealth());
			m_player1->setDamage(player1->getDamage());
			/*m_player2->setHealth(player2->getHealth());
			m_player2->setDamage(player2->getDamage());*/
			break;
		}
	}
}

void Game::update()
{
	m_player1->attack(m_player2);
	m_player2->attack(m_player1);

	std::fstream file;

	file.open("saveData.txt", std::ios::out | std::ios::binary);

	file << m_player1->getHealth() << std::endl;
	file << m_player1->getDamage();
	/*file << m_player2->getHealth() << std::endl;
	file << m_player2->getDamage();*/
	file.close();
}

void Game::draw()
{
	std::cout << "Player1 health is : " << m_player1->getHealth() << std::endl;
	std::cout << "Player2 health is : " << m_player2->getHealth() << std::endl;
}

void Game::end()
{
	delete m_player1;
	delete m_player2;
}
