#include <stdio.h>

#define		MXARY			100+5

void	insertionSort(int A[MXARY], int);

int		A[MXARY]={'\0'};

int		main(void)
{
	int		N;
	int		k;

	scanf("%d",&N);
	for(k=0; k<N; k++)
	{
		scanf("%d",&A[k]);
	}
	for(k=0; k<N-1; k++)
	{
		printf("%d ",A[k]);
	}
	printf("%d\n",A[k]);
	insertionSort(A, N);
	return 0;
}

void 	insertionSort(int A[MXARY], int N)
{
	int		i, j, k;
	int		v;

	for(i=1; i<N; i++)
	{
		v = A[i];
		j = i - 1;

		while( j >= 0 && A[j] > v )
		{
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		for(k=0; k<N-1; k++)
		{
			printf("%d ",A[k]);
		}
		printf("%d\n",A[k]);
	}
}
