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
	int num = 0;
	
	std::cout << "Think of a number between 1 - 10 for me to guess" << std::endl;
	 
	int numbers[10];
	int min = 1;
	int max = 10;
	int goal = 5;

	while (min <= max)
	{
		int guess = (min + max) / 2;

		if (numbers[guess] == goal)
			return guess;
		else if (numbers[guess] < goal)
			min = guess + 1;
		else if (numbers[guess] > goal)
			max = guess - 1;

	}

	system("pause");
	return 0;
}