#include <stdio.h>

int insertSort(int*, int);

int main()
{
	int arr[100];
	int num = 0, temp = 0, re = 0;
	
	scanf(" %d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf(" %d", &temp);
		arr[i] = temp;
	}

	re = insertSort(arr, num);

	for (int i = 0; i < num; i++)
	{
		printf("%d", arr[i]);
		if (i < num - 1) printf(" ");
	}
	printf("\n");
	printf("%d\n", re);

	return 0;
}

int insertSort(int arr[], int num)
{
	int cnt = 0, min = 0, temp = 0;
	for(int i = 0; i < num; i++)
	{
		min = i;
		for (int j = i; j < num; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (i != min) cnt++;
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	return cnt;
}


