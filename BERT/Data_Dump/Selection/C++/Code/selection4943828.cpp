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
	for(int i = 0; i < size; ++i)
	{
		int mini = i;
		for(int j = i; j < size; ++j)
		{
			if(array[j] < array[mini]) mini = j;
		}
		if(mini != i)
		{
			int temp = array[i];
		    array[i] = array[mini];
		    array[mini] = temp;	
		    ++swap;
		}
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
