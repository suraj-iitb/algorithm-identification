#include<stdio.h>

int main(){
	int A[101], N, i, swap, count, j, l;

	scanf("%i", &N);

	/* input array */

	for (l= 0; l<N; l++)
	{
		scanf("%d", &A[l]);
	}

	
	/* algorithm */
	for (i = 0; i < N; i++)
	{
		int mini = i;
		for (j = i; j <= N-1; j++)
		{
			if (A[j] < A[mini])
			{
				mini = j;
			}
		}
		swap = A[i];
		A[i] = A[mini];
		A[mini] = swap;
		if (i != mini){
			count++;
		}
		
	}

	/* printing result */

	int k;
	for (k = 0; k < N-1; k++)
	{
		printf("%d ", A[k]);
	}
	printf("%d", A[N-1]);
	printf("\n");
	printf("%i\n", count);

	return 0;
	
}


