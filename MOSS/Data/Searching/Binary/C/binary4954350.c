#include<stdio.h>
int binarySearch( int A[], int n, int key );
int main (void)
{
	int i;
	int n, q, T;
	int S[100000+1] = {0};
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
		
		if( binarySearch( S, n, T ) == 0 )
		{
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
int binarySearch( int A[], int n, int key )
{
	int left = 0;
	int right = n;
	
	int mid;
	
	while( left < right )
	{
		mid = ( left + right ) / 2;
		
		if( A[mid] == key )
		{
			return 0;
		}
		else if( key < A[mid] )
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	
	return 1;
}
