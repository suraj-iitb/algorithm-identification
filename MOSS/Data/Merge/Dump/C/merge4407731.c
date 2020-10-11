#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ABS(x) ( (x)>0 ? x : -(x) )
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )

#define INF 1000000000



//typedef long long ll;

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*

int binary_search(int* a, int n,int key)
{
	int low, middle, high;

	low = 0, high = n - 1;

	while (low <= high)
	{
		middle = (low + high) / 2;

		if (key < a[middle])
			high = middle - 1;
		else if (key > a[middle])
			low = middle + 1;
		else
			return 1;
	}
	return 0;
}

void reverse(int a[], int b, int e)
{
	int i;

	for (i = 0; i <= (e-b-1) / 2; i++)
	{
		swap(&a[b+i], &a[e - 1 - i]);
	}
}

void CountingSort(int A[],int k,int n)
{
	int B[2000000] = { 0 };

	int i, C[20000] = { 0 };

	for (i = 0; i < n; i++)
		C[A[i]]++;

	for (i = 0; i < k; i++)
		C[i + 1] += C[i];

	for (i = n - 1; i >= 0; i--)
		B[--C[A[i]]] = A[i];

	for (i = 0; i < n; i++)
	{
		printf("%d", B[i]);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");
}
*/

int partion(int A[], int l, int r)
{
	int i, j, pivot, t;

	i = l - 1;
	j = r;
	pivot = A[r];

	for (;;)
	{
		while (A[++i] < pivot)
			;
		while (i < --j && pivot < A[j])
			;

		if (i >= j)
			break;
		swap(&A[i], &A[j]);
	}

	swap(&A[i], &A[r]);
	return i;
}

void quickSort2(int A[], int l, int r)
{
	int v;

	if (l >= r)
		return;

	v = partion(A, l, r);

	quickSort2(A, l, v-1);

	quickSort2(A, v+1, r);
}

void quickSort(int A[], int n)
{
	quickSort2(A, 0, n - 1);
}

int B[500000];
int count = 0;

void mergeSort(int A[], int low,int high)
{
	int mid, i, j, k;

	if (low >= high)
		return;

	mid = (low + high) / 2;

	mergeSort(A, low, mid);
	mergeSort(A, mid + 1, high);

	for (i = low; i <= mid; i++)
		B[i] = A[i];

	for (i = mid + 1, j = high; i <= high; i++, j--)
		B[i] = A[j];

	i = low, j = high;

	for (k = low; k <= high; k++)
	{
		count++;
		if (B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j--];
	}
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

int main()
{
	int i,n;
	int S[500000];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);

	mergeSort(S, 0, n - 1);

	print(S, n);

	printf("%d\n", count);
}
