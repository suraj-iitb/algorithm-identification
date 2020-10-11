#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int selectionSort(int arr[], int n);
void swap(int* a, int* b);
int main(void)
{
	int n;
	int count;
	int arr[110];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	count = selectionSort(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n%d\n", arr[n - 1], count);
	return 0;
}
int selectionSort(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(&arr[i], &arr[min]);
			count++;
		}
	}
	return count;
}

void swap(int* a, int* b)
{
	int cache = *a;
	*a = *b;
	*b = cache;
}
