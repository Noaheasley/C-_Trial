#include <iostream>
#include <string>

char board[3][3] = { {'_','_','_'},
				    {'_','_','_'},
				    {'_','_','_'} };
char name1[16];
char name2[16];
char letterX[3][3] = { {'X','X','X'},
					{'X','X','X'},
					{'X','X','X'} };
char letterO[3][3] = { {'O','O','O'},
					{'O','O','O'},
					{'O','O','O'} };
bool takenX;
bool takenO;
bool gameOver = false;
bool winX = false;
bool winO = false;
bool row0Clear = false;
bool row1Clear = false;
bool row2Clear = false;
int number = 1;
int takenSpot = 10;
int openSpot = 11;
void pickArrayX()
{
	int x;
	int y;
	std::cout << "X Pick a spot" << std::endl;
	std::cout << "Enter the cordinate for X (the numbers on the side of the board of zeros)" << std::endl;
	std::cin >> x;
	std::cout << "Enter the cordinate for Y (the numbers on top of the board of zeros)" << std::endl;
	std::cin >> y;
	if (board[x][y] == letterO[x][y])
	{

		while (board[x][y] == letterX[x][y])
		{
			std::cout << "You can't use that spot" << std::endl;
			std::cout << "X Pick a spot" << std::endl;
			std::cout << "Enter the cordinate for X (the numbers on the side of the board of zeros)" << std::endl;
			std::cin >> x;
			std::cout << "Enter the cordinate for Y (the numbers on top of the board of zeros)" << std::endl;
			std::cin >> y;

			if (board[x][y] == letterX[x][y])
			{
				std::cout << "You've claimed this spot already" << std::endl;
				return;
			}
			else if (board[x][y] != letterX[x][y] && board[x][y] != letterO[x][y])
			{
				board[x][y] = letterX[x][y];
				break;
			}
		}
	}
	else if (board[x][y] != letterO[x][y])
	{
		board[x][y] = letterX[x][y];
	}

	system("pause");
	system("cls");
}
void pickArrayO()
{
	int x;
	int y;
	std::cout << "O Pick a spot" << std::endl;
	std::cout << "Enter the cordinate for X (the numbers on the side of the board of zeros)" << std::endl;
	std::cin >> x;
	std::cout << "Enter the cordinate for Y (the numbers on top of the board of zeros)" << std::endl;
	std::cin >> y;
	if (board[x][y] == letterX[x][y])
	{

		while (board[x][y] == letterO[x][y])
		{
			std::cout << "You can't use that spot" << std::endl;
			std::cout << "O Pick a spot" << std::endl;
			std::cout << "Enter the cordinate for X (the numbers on the side of the board of zeros)" << std::endl;
			std::cin >> x;
			std::cout << "Enter the cordinate for Y (the numbers on top of the board of zeros)" << std::endl;
			std::cin >> y;

			if (board[x][y] == letterO[x][y])
			{
				std::cout << "You've claimed this spot already" << std::endl;
				return;
			}
			else if (board[x][y] != letterO[x][y] && board[x][y] != letterX[x][y])
			{
				board[x][y] = letterO[x][y];
				break;
			}
		}
	}
	else if(board[x][y] != letterX[x][y])
	{
		board[x][y] = letterO[x][y];
	}
	
	system("pause");
	system("cls");
}
int pickALetter()
{
	int num = 0;
	while (num != 1 || num != 2)
	{
		std::cout << "Choose your Letter " << name1 << std::endl;
		std::cout << "\n1. X" << "\n2. O" << std::endl;

		std::cin >> num;
		if (num == 1)
		{
			return takenX = true;
		}
		else if (num == 2)
		{
			return takenO = true;
		}
	}
}
void winConX()
{
	number += 1;
	if ((board[0][0] == letterX[0][0]) && (board[1][1] == letterX[1][1]) && (board[2][2] == letterX[2][2]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[0][2] == letterX[0][2]) && (board[1][1] == letterX[1][1]) && (board[2][0] == letterX[2][0]))
	{
		winX = true;
		gameOver = true;
	}
	else if((board[0][0] == letterX[0][0]) && (board[0][1] == letterX[0][1]) && (board[0][2] == letterX[0][2]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[1][0] == letterX[1][0]) && (board[1][1] == letterX[1][1]) && (board[1][2] == letterX[1][2]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[2][0] == letterX[2][0]) && (board[2][1] == letterX[2][1]) && (board[2][2] == letterX[2][2]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[0][0] == letterX[0][0]) && (board[1][0] == letterX[1][0]) && (board[2][0] == letterX[2][0]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[0][1] == letterX[0][1]) && (board[1][1] == letterX[1][1]) && (board[2][1] == letterX[2][1]))
	{
		winX = true;
		gameOver = true;
	}
	else if ((board[0][2] == letterX[0][2]) && (board[1][2] == letterX[1][2]) && (board[2][2] == letterX[2][2]))
	{
		winX = true;
		gameOver = true;
	}
	else
		return;
}
void winConO()
{
	number += 1;
	if ((board[0][0] == letterO[0][0]) && (board[1][1] == letterO[1][1]) && (board[2][2] == letterO[2][2]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[0][2] == letterO[0][2]) && (board[1][1] == letterO[1][1]) && (board[2][0] == letterO[2][0]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[0][0] == letterO[0][0]) && (board[0][1] == letterO[0][1]) && (board[0][2] == letterO[0][2]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[1][0] == letterO[1][0]) && (board[1][1] == letterO[1][1]) && (board[1][2] == letterO[1][2]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[2][0] == letterO[2][0]) && (board[2][1] == letterO[2][1]) && (board[2][2] == letterO[2][2]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[0][0] == letterO[0][0]) && (board[1][0] == letterO[1][0]) && (board[2][0] == letterO[2][0]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[0][1] == letterO[0][1]) && (board[1][1] == letterO[1][1]) && (board[2][1] == letterO[2][1]))
	{
		winO = true;
		gameOver = true;
	}
	else if ((board[0][2] == letterO[0][2]) && (board[1][2] == letterO[1][2]) && (board[2][2] == letterO[2][2]))
	{
		winO = true;
		gameOver = true;
	}
	else
		return;
}

void ticTacToe()
{
	if (takenX == true)
	{
		std::cout << name1 << " is X" << std::endl;
		std::cout << name2 << " is O" << std::endl;
	}
	else if (takenO == true)
	{
		std::cout << name1 << " is O" << std::endl;
		std::cout << name2 << " is X" << std::endl;
	}
	while (number <= 10)
	{



		
		std::cout << " "<< "0" << "1" << "2" << std::endl;
		std::cout << "0" << board[0][0] << board[0][1] << board[0][2] << std::endl;
		std::cout << "1" << board[1][0] << board[1][1] << board[1][2] << std::endl;
		std::cout << "2" <<board[2][0] << board[2][1] << board[2][2] << std::endl;

		pickArrayX();
		winConX();
		if (number >= 10)
		{
			gameOver == true;
		}
		if (gameOver == true)
		{
			break;
		}

		std::cout << " " << "0" << "1" << "2" << std::endl;
		std::cout << "0" << board[0][0] << board[0][1] << board[0][2] << std::endl;
		std::cout << "1" << board[1][0] << board[1][1] << board[1][2] << std::endl;
		std::cout << "2" << board[2][0] << board[2][1] << board[2][2] << std::endl;
		pickArrayO();
		winConO();
		if (number >= 10)
		{
			gameOver == true;
		}
		
		if (gameOver == true)
		{
			break;
		}
	}
	if (winO == true && takenX == true)
	{
		std::cout << name2 << " is the winner!" << std::endl;
	}
	else if (winO == true && takenO == true)
	{
		std::cout << name1 << " is the winner!" << std::endl;
	}
	else if (winX == true && takenX == true)
	{
		std::cout << name1 << " is the winner!" << std::endl;
	}
	else if (winX == true && takenO == true)
	{
		std::cout << name2 << " is the winner!" << std::endl;
	}
	else
	{
		std::cout << "It was a draw" << std::endl;
	}
	system("pause");

}
int main()
{
	std::cout << "Enter your name Player1" << std::endl;
	std::cin >> name1;
	std::cout << "\nEnter your name Player2" << std::endl;
	std::cin >> name2;


	system("cls");

	pickALetter();



	ticTacToe();
	/*int numbers[]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	PrintArray(numbers,11);*/


	//numbers[3 * 2] = 9;
	//int index = 2;
	//numbers[index] = 4;
	//int xNumber = numbers[index];
	//int yNumber = numbers[index + 1];

	
}

