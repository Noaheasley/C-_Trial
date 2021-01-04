#include <iostream>
#include <fstream>
#include "Character.h"


bool binaryFileExample()
{
	Character sbeve = Character();
	sbeve.health = 100;
	sbeve.damage = 20;
	Character sbeve1 = Character();
	sbeve1.health = 190;
	sbeve1.damage = 25;
	Character sbeve2 = Character();
	sbeve2.health = 10;
	sbeve2.damage = 200;

	std::fstream file;

	file.open("saveBin.txt", std::ios::out | std::ios::binary);
	if (!file.is_open())
		return false;

	file.write((char*)&sbeve, sizeof(Character));
	file.write((char*)&sbeve1, sizeof(Character));
	file.write((char*)&sbeve2, sizeof(Character));
	file.close();

	Character sbeve4 = Character();
	file.open("saveBin.txt", std::ios::in | std::ios::binary);

	if (!file.is_open())
		return false;

	file.seekg(sizeof(Character) * 2, std::ios::beg);

	file.read((char*)&sbeve4, sizeof(Character));
	
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;
	file.close();
	return true;
}


int main()
{
	binaryFileExample();
	//Character player = Character();
	//player.health = 100;
	//player.damage = 5;

	////Example of saving to a text file

	////Create an instance of a file stream
	//std::fstream file;

	////Search for the file with the name given in the first
	////argument. If no file with this name exists, one with
	////the name is created. Then "std::ios::out" is used to
	////say that we want to output data to the text file.
	//file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	////Check is the file isn't opened. If so, return from main.
	//if (!file.is_open())
	//{
	//	return 1;
	//}

	//
	////Write player stats to the text file.
	//file << player.health << std::endl;
	//file << player.damage;

	////Close the file when we're done.
	//file.close();


	////Example of loading from a text file.
	//Character player2 = Character();
	//
	////Search for a file that has the name given in the first
	////argument. The "std::ios::in" argument is used to say 
	////that we want to get input from the file.
	//file.open("save.txt", std::ios::in);

	////Check is the file isn't opened. If so, return from main.
	//if (!file.is_open())
	//{
	//	return 1;
	//}

	////Reads the player stats from the text file.
	//file >> player2.health;
	//file >> player2.damage;

	////Closes the file once we're done
	//file.close();

	//std::cout << player2.health << std::endl;
	//std::cout << player2.damage << std::endl;
	//return 0;
}