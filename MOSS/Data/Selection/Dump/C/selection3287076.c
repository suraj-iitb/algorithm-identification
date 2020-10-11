#include<stdio.h>
#include<math.h>
int search(int *, int,int);
void swap(int *, int*);
int main() {
	int A[100],n,i,minj = 0,tail = 0,count = 0;
	scanf("%d", &n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for ( i = 0; i < n; i++)
	{
		minj = search(A, tail, n);
		if (tail != minj) {
			swap(&A[tail], &A[minj]);
			count++;
		}
		tail++;
	}
	for ( i = 0; i < n; i++)
	{
		if (i == 0)
		{
			printf("%d", A[i]);
		}
		else
		{
			printf(" %d", A[i]);
		}
	
	}
	printf("\n");
	printf("%d", count);
	printf("\n");
	return 0;
}
int search(int *A, int tail, int n) {
	int minj = tail;
	int i;
	for (i = tail; i < n; i++)
	{
		if (A[minj] > A[i]) {
			minj = i;
		}
	}
	return minj;
}
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
