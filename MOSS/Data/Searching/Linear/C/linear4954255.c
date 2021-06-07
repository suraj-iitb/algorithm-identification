#include<stdio.h>
int linearSearch( int A[], int n, int key );
int main (void)
{
	int i;
	int n, q, T;
	int S[10000+1] = {0};
	int count = 0;
	
	scanf("%d", &n);
	
	for( i=0; i<n; i++ )
	{
		scanf("%d", &S[i]);
	}
	
	scanf("%d", &q);
	
	for( i=0; i<q; i++ )
	{
		scanf("%d", &T);
		
		if( linearSearch( S, n, T ) == 0)
		{
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
int linearSearch( int A[], int n, int key )
{
	int i;
	
	i = 0;
	A[n] = key;
	
	while( A[i] != key )
	{
		i++;
	}
	
	if( i >= n )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
