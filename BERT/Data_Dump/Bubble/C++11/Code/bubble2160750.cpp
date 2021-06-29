#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
	}

	int numSwap = 0;
	int temp = 0;
	int bubble = 0;
	bool isContinue = true;
	while(isContinue)
	{
		isContinue = false;
		for (int j = n - 1; j > 0; j--)
		{
			if (input[j - 1] > input[j])
			{
				temp = input[j];
				input[j] = input[j - 1];
				input[j - 1] = temp;
				numSwap++;
				isContinue = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << input[i];
		if (i != n - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << "\n" << numSwap << std::endl;
}
