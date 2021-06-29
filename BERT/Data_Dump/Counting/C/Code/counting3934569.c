#include<stdio.h>

#define MAX 2000100

int A[2000100], B[2000100], C[2000100];
int n;

void countingSort()
{
	for (int i = 0; i < n; i++)
		C[A[i]]++;
	for (int i = 1; i <= MAX; i++)
		C[i] = C[i] + C[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}

}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	countingSort();
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
}
