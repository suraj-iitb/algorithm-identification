#include<stdio.h>

int bubbleSort(int a[], int n)
{
	int i, j, temp;
	int swap = 0;
	
	for(i = 0; i <= n; i++)
	{
		for(j = n - 1; j >= i + 1; j--)
		{
			if(a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				swap++;
			}
		}
	}
	
	return swap;
}

int main(void)
{
	int n, i, swap;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i = 0; i < n; i++)
	{
		if(i != n - 1)
		{
			scanf("%d ", &a[i]);
		}
		else
		{
			scanf("%d", &a[i]);
		}
	}
	
	swap = bubbleSort(a, n);
	
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
	
