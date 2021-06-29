#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX_LEN 100

using namespace std;

int a[MAX_LEN];

void printArray(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", a[i]);
		if (i != len - 1) printf(" ");
	}
	printf("\n");
}

void swap(int *a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int main()
{
	int len;
	scanf("%d", &len);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
	}

	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])min = j;
		}
		if (min != i)
		{
			count++;
			swap(a, i, min);
		}
	}
	printArray(a, len);
	printf("%d\n", count);
}
