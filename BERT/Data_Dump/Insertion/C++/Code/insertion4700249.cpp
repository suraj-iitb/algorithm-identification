//
// Created by in on 20/7/25.
//

#include<bits/stdc++.h>

using namespace std;

void printArray (int* arr, int size);

void insertionSort (int* arr, int size);

int main ()
{
	int n;
	int a[100];

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	printArray(a, n);
	insertionSort(a, n);

	return 0;
}

void printArray (int* arr, int size)
{
	int i = 0;
	for(; i < size - 1; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);
}

void insertionSort (int* arr, int size)
{
	int tmp;
	for(int i = 1; i < size; ++i)
	{
		tmp = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = tmp;
		printArray(arr, size);

	}
}
