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
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		printArr(arr, n);
		int j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	printArr(arr, n);
	return 0;
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
