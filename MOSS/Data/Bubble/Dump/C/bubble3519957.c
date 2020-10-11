#include <stdio.h>
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int bubblesort(int a[], int N, int count)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(&a[j], &a[j - 1]);
				++count;
			}
		}
	}
	return count;
}

void print(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i != N - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	int count = 0;
	int a[100];
	int N;
	scanf("%d", &N);

	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}



	count = bubblesort(a, N, count);
	print(a, N);
	printf("%d\n", count);


	return 0;
}
