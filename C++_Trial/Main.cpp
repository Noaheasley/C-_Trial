#include <iostream>


//void FizzBuzz(int num)
//{
//	for (int i = 0; i <= num; i++)
//	{
//		if (i % 3 == 0 && i % 5 == 0)
//		{
//			std::cout << i << "FizzBuzz" << std::endl;
//		}
//		else if (i % 3 == 0)
//		{
//			std::cout << i << "Fizz" << std::endl;
//		}
//		else if (i % 5 == 0)
//		{
//			std::cout << i << "Buzz" << std::endl;
//		}
//	}
//}

int main()
{
	
	//for (int i = 0; i <= 100; i+=2)
	//FizzBuzz(num);
	
	
	std::cout << "Think of a number between 1 - 10 for me to guess" << std::endl;
	
	
	int length = 10;
	int min = 1;
	int max = 10;

	

	while (min <= max)
	{
		int num = 0;
		int higher = 1;
		bool lower = 2;
		bool correct = 3;
		int guess = (min + max) / 2;

		std::cout << "Is this your number? " << guess << std::endl;

		std::cout << "1. Lower" << std::endl;
		std::cout << "2. Higher" << std::endl;
		std::cout << "3. Correct" << std::endl;


		
		std::cin >> num;
		
		
		if (num == 1)
		{
			if (min == max)
			{
				std::cout << "liar -_-" << std::endl;
			}
			max = guess - 1;

		}
		else if (num == 2)
		{
			if (min == max)
			{
				std::cout << "liar -_-" << std::endl;
			}
			min = guess + 1;

		}
		else if (num == 3)
		{
			std::cout << "Yay :D" << std::endl;
			break;
		}
		
		/*if (numbers[guess] == goal)
			return guess;
		else if (numbers[guess] < goal)
			min = guess + 1;
		else if (numbers[guess] > goal)
			max = guess - 1;*/

	}

	system("pause");
	return 0;
}