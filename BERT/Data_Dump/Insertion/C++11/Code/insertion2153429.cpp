#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> numbers(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
	}

	for (int j = 0; j < n; j++)//??¨???
	{
		std::cout << numbers[j];
		if (j != n - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	int inserting = 0;
	for (int i = 1; i < n; i++)
	{
		inserting = numbers[i];
		for (int j = i; j > 0; j--)
		{
			if (numbers[j - 1] > inserting)
			{
				numbers[j] = numbers[j - 1];
				numbers[j - 1] = inserting;
			}
			else
			{
				break;
			}
		}

		for (int j = 0; j < n; j++)//??¨???
		{
			std::cout << numbers[j];
			if (j != n - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
