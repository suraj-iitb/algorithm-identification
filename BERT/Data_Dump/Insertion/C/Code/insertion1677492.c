#include <stdio.h>

void printA(int, int *);

int main(void)
{
	int i, j, v, n, A[100];
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&A[i]);
	}
	printA(n, A);
	for (i=1; i<n; i++) {
		v = A[i];
		j = i-1;
		while(j>=0 && A[j]>v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		printA(n, A);
	}
	return 0;
}

void printA(int n, int *A)
{
	int i;
	for (i=0; i<n-1; i++) {
		printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
}
