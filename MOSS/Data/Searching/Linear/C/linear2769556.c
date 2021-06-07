#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, q, i, j, count = 0;
	int *S, *T;
	
	scanf("%d", &n);
	S = (int*)malloc(n * sizeof(int));
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	
	scanf("%d", &q);
	T = (int*)malloc(q * sizeof(int));
	for(i=0; i<q; i++)
	{
		scanf("%d", &T[i]);
	}
	
	for(i=0; i<q; i++)
	{
		for(j=0; j<n; j++)
		{
			if(T[i]==S[j])
			{
				count++;
				break;
			}
		}
	}
	
	printf("%d\n", count);
	
}	
