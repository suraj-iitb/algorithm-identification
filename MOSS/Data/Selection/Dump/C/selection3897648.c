#include<stdio.h>

int selectionSort(int a[], int n)
{
	int i, j, min, temp;
	int swap = 0;
	
	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i; j < n; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		if(i != min)
		{
			swap++;
		}
	}
	
	return swap;
}

int main(void)
{
	int n, i;
	int swap = 0;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	swap = selectionSort(a, n);
	
	for(i = 0; i < n; i++)
	{
		if(i != n - 1)
		{
			printf("%d ", a[i]);
		}
		else
		{
			printf("%d\n", a[i]);
		}
	}
	
	printf("%d\n", swap);
	
	return 0;
}

