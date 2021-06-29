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
	int sortCnt = 0;
	for (int i = 0; i < n; ++i)				// i表示已冒泡的元素
	{
		bool isBubbled = false;
		for (int j = n - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
				++sortCnt;
				isBubbled = true;
			}
		}
		if (!isBubbled) break;
	}
	printArr(arr, n);
	std::cout << sortCnt << std::endl;
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
