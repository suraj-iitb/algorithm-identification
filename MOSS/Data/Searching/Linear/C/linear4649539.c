#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ABS(x) ( (x)>0 ? x : -(x) )
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )

#define MOD 1000000007

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");
}

void insertionSort(int A[], int N)
{
	int i, j,tmp;

	for (i = 1; i < N; i++)
	{
		j = i;
		while (j > 0 && A[j - 1] > A[j])
		{
			tmp = A[j - 1];
			A[j - 1] = A[j];
			A[j] = tmp;

			j--;
		}
		print(A, N);
	}
}

void bubbleSort(int A[], int N,int *count)
{
	int flag = 0;
	int i, j,tmp;

	for (i = 0; i < N; i++)
	{
		for (j = N - 1; j > 0; j--)
		{
			if (A[j - 1] > A[j])
			{
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
				flag = 1;
				(*count)++;
			}
		}
		if (flag == 0)
			break;
		else
			flag = 0;
	}
}

void selectionSort(int A[], int N,int *count)
{
	int i, j;
	int key,tmp;

	for (i = 0; i < N; i++)
	{
		key = i;
		for (j = i; j < N; j++)
		{
			if (A[j] < A[key])
				key = j;
		}
		if (i != key)
		{
			tmp = A[i];
			A[i] = A[key];
			A[key] = tmp;
			(*count)++;
		}
	}
}


int binary_search(int A[], int N, int key)
{
	int left, right, middle;

	left = 0, right = N - 1;

	while (left <= right)
	{
		middle = (left + right) / 2;
		if (A[middle] == key)
			return 1;
		else if (A[middle] > key)
			right = middle - 1;
		else if (A[middle] < key)
			left = middle + 1;
	}
	return 0;
}

#define SIZE 1000

int stack[SIZE];
int pos;

void init()
{
	pos = 0;
}

int isEmpty()
{
	if (pos == SIZE)
	{
		printf("ERROR\n");
		return 1;
	}
	return 0;
}

void push(int x)
{
	stack[pos++] = x;
}

int pop()
{
	int x;
	x = stack[--pos];

	return x;
}

int main()
{
	int i, j, n, q;
	int S[100000], T[10000];

	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);

	scanf("%d", &q);

	for (i = 0; i < q; i++)
		scanf("%d", &T[i]);

	for (i = 0; i < q; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (T[i] == S[j])
			{
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
