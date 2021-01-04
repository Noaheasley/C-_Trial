#include "Game.h"
#include "Character.h"
#include <fstream>
#include <iostream>

std::fstream file;

void Game::run()
{
	start();

	while (getGameOver() == false)
	{
		update();
		draw();
	}

	end();
}

bool binaryFile()
{
	Character player1 = Character();
	player1.getHealth();
	player1.getDamage();
	Character player2 = Character();
	player2.getHealth();
	player2.getDamage();

	std::fstream file;

	file.open("saveBin.txt", std::ios::out | std::ios::binary);
	if (!file.is_open())
		return false;

	file.write((char*)&player1, sizeof(Character));
	file.write((char*)&player2, sizeof(Character));
	file.close();

	Character lPlayer1 = Character();
	file.open("saveBin.txt", std::ios::in | std::ios::binary);

	if (!file.is_open())
		return false;

	file.seekg(sizeof(Character), std::ios::beg);

	file.read((char*)&lPlayer1, sizeof(Character));

	std::cout << lPlayer1.getHealth() << std::endl;
	std::cout << lPlayer1.getDamage() << std::endl;
	file.close();
	return true;
}

void Game::start()
{
	Character* m_player1 = new Character(100, 10);
	Character* m_player2 = new Character(100, 10);

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
