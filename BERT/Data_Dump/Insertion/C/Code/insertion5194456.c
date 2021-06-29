#include <stdio.h>
#define N 100

int main()
{
	int n, A[N], i, j, v;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		if(i < n - 1) printf("%d ", A[i]);
		else printf("%d\n", A[i]);
	}
	
	for(i = 1; i < n; i++)
	{
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		
		for(j = 0; j < n; j++)
		{
			if(j < n - 1) printf("%d ", A[j]);
			else printf("%d\n", A[j]);
		}
	}
	
	return 0;
}
