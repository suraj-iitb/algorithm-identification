#pragma warning( disable:4996 )

#include <stdio.h>
#include <memory.h>
#define MAX_K 10000

int A[2000000];
int B[2000000];

void CountingSort(int A[], int B[], int n)
{
	int C[MAX_K+1];
	int i;
	memset(C, 0, sizeof(C));
	for (i = 0;i < n; i++)
	{
		C[A[i]]++;
	}
	for (i = 1; i <= MAX_K; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (i = n-1; i >= 0; i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	return;
}

int main()
{
	int i, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	memset(B, 0, sizeof(B));
	CountingSort(A, B, n);
	for (i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
	return 0;
}

