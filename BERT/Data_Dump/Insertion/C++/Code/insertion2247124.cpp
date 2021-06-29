#include <stdio.h>

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

void insertionSort(int *arr,int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i-1;
		int v = arr[i];
		while (j >= 0 && arr[j]>v)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		printArr(arr, size);
	}
}

int main()
{
	int arr[100];
	int N = 0;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);

	printArr(arr,N);
	insertionSort(arr, N);

    return 0;
}
