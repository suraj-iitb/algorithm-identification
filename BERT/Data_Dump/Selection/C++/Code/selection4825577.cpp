#include <iostream>
#define N 100

void printArr(int* arr, int n);

int main()
{
	int n;
	std::cin >> n;
	int arr[N];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	int swapCnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;	
			}
		}
		if (minIndex != i)
		{
			std::swap(arr[minIndex], arr[i]);
			++swapCnt;
		}
	}
	printArr(arr, n);
	std::cout << swapCnt << std::endl;
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i != 0) std::cout << " ";
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
