#include <stdio.h>

int main ()
{
	int i, N, v, A[100], j;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf ("%d", &A[i]);
	}
	printf ("%d", A[0]);
	for (i = 1; i < N; i++) {
		printf (" %d", A[i]);
	}
	putchar ('\n');
	
	for (i = 1; i <= N - 1; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		
		printf ("%d", A[0]);
		for(j = 1; j < N; j++) {
			printf (" %d", A[j]);
		}
		putchar ('\n');
	}
	
	return 0;
}
