#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int bubbleSort(int arr[], int n);
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
	count = bubbleSort(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n%d\n", arr[n - 1], count);
	return 0;
}
int bubbleSort(int arr[], int n)
{
	int count = 0;
	int flag = 1;
	while (flag)
	{
		int start = 0;
		
		flag = 0;
		for (int i = n - 1; i > start; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(&arr[i], &arr[i - 1]);
				count++;
				flag = 1;
			}
		}
		start++;
	}
	return count;
}

void swap(int* a, int* b)
{
	int cache = *a;
	*a = *b;
	*b = cache;
}
