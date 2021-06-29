#include <iostream>

void input(int* array, int& size)
{
	std::cin >> size;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> array[i];
	}
}

void print(int* array, int size)
{
	for(int i = 0; i < size; ++i)
	{
		if(i == 0) std::cout << array[i];
		else std::cout << ' ' << array[i];
	}
}

void output(int* array, int size) //Straight Selection Sort
{
	int swap = 0;
	for(int i = 1; i < size; ++i)
	{
		bool swapped = false;
		for(int j = size - 1; j >= i; --j)
		{
			if(array[j] < array[j-1])
			{
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
				++swap;
				swapped = true;
			}
		}
		if(swapped == false) break;
		else continue;
	}
	
	print(array, size);
	std::cout << '\n';
	std::cout << swap << '\n';
}

int main()
{
	int size;
	int* array = new int[size];
	input(array, size);
	
	output(array, size);
	
	return 0;
}
