#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

void CountingSort(int *,int *,int);

int main()
{
	unsigned short *A,*B;
	int C[VMAX+1];
	int n,i;
	int k = 0;
	int tmp;

	scanf("%d",&n);

	A = malloc(sizeof(short)*n+1);
	B = malloc(sizeof(short)*n+1);

	for(i = 0; i < n; i++)
	{
		scanf("%d",&tmp);
		A[i] = tmp;
		if(A[i] > k)
		{
			k = A[i];
		}
	}

	for(i = 0; i <= k; i++)
	{
		C[i] = 0;
	}

	for(i  = 0; i < n; i++)
	{
		C[A[i]]++;
	}

	for(i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i-1];
	}

/*	for(i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	*/
	for(i = n-1; i >= 0; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	for(i = 1; i < n; i++)
	{
		printf("%d ",B[i]);
	}
	printf("%d\n",B[i]);


	return 0;
}


