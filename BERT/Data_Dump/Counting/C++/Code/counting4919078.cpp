#include <iostream>

void countingSort(int* array, int size)
{
	int order[10001]{};
	for(int i = 0; i < size; ++i)
	{
		++order[array[i]];
	}
	for(int i = 1; i < 10001; ++i)
	{
		order[i] += order[i-1];
	}
	int* ans = new int[size];
	for(int i = size - 1; i >= 0; --i)
	{
		int position = order[array[i]] - 1;
		ans[position] = array[i];
		--order[array[i]];
	}
	
	for(int i = 0; i < size; ++i)
	{
		if( i == 0) std::cout << ans[i];
		else std::cout << ' ' << ans[i];
	}
	std::cout << '\n';
}

int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	countingSort(arr, n);
}
