#include<stdio.h>

//int bubbleSort(int *a, int N)
//{
//	int swap = 0, flag = 1;
//	int i, j;
//	for (i = 0; flag; i++)
//	{
//		flag = 0;
//		for (j = N - 1; j > i; j--)
//		{
//			if (a[j] < a[j - 1])
//			{
//				int t = a[j];
//				a[j] = a[j - 1];
//				a[j - 1] = t;
//				swap++;
//				flag = 1;
//			}
//		}
//	}
//	return swap;
//}

int bubbleSort(int *a, int N)
{
	int swap = 0, flag = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
				swap++;
			}
		}
	}
	return swap;
}

void print(int *a, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
}

int main()
{
	int N;
	int a[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int sw = bubbleSort(a, N);
	print(a, N);
	printf("\n%d\n", sw);
}
