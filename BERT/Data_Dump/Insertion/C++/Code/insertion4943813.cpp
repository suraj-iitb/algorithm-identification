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

void output(int* array, int size) //Straight Insertion Sort
{
	for(int i = 0; i < size; ++i)
	{
		if(i == 0)
		{
			print(array, size);
			std::cout << '\n';
		}
		else
		{
			int j = i - 1;
			int key = array[i];
			while(j >= 0 && array[j] > key)
			{
				array[j+1] = array[j];
				--j;
			}
			array[j+1] = key;
			
		
			print(array, size);
			std::cout << '\n';
		}
	}
}

int main()
{
	int size;
	int* array = new int[size];
	input(array, size);
	
	output(array, size);
	
	return 0;
}
