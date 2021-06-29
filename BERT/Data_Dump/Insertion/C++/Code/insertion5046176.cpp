#include <iostream>

void insertion_sort(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int v = arr[i];
		
		int j = i - 1;
		while (j >= 0 && arr[j] > v)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = v;
		
		for (int k = 0; k < N; k++)
		{
			std::cout << arr[k];
			
			if (k == N - 1)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << ' ';
			}
		}
	}
}

int main(void)
{
	int N;
	std::cin >> N;
	int* arr = new int[N];
	for(int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		
		std::cout << arr[i];
			
		if (i == N - 1)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << ' ';
		}
	}
	
	insertion_sort(arr, N);
}
