#include <stdio.h>

int bubbleSort(int*, int);

int main()
{
	int arr[100];
	int temp, num = 0, re = 0;

	scanf(" %d", &num);

	for(int i = 0; i < num; i++)
	{
		scanf(" %d", &temp);
		arr[i] = temp;
	}


	re = bubbleSort(arr, num);
	
	for (int i = 0; i < num; i++)
	{
		printf("%d", arr[i]);
		if (i < num-1) printf(" ");
	}
	printf("\n");
	printf("%d\n",re);
	return 0;
}

int bubbleSort(int arr[], int num)
{
	int temp = 0;
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j >= i+1; j--)
		{
			if (arr[j] < arr[j-1])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				cnt++;
			}
		}
	}
	return cnt;
}

