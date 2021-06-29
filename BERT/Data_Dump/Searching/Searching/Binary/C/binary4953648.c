#include<stdio.h>

int n;
int S[100000];

int binarySearch(int key, int n)
{
	int left=0;
	int right=n;
	int mid;
	
	while(left < right)
	{
		mid = (left + right)/2;
		if( S[mid] == key )
		{
			return 1;
		}
		else if( key < S[mid] )
		{
			right = mid;
		}
		else
		{
			left = mid + 1; 
		}	
	}
	return 0;
}

int main(void)
{
	int n, q, i, se;
	int count=0;
	int T[50000];
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	
	scanf("%d", &q);
	for(i=0; i<q; i++)
	{
		scanf("%d", &T[i]);
	}
	
	for(i=0; i<q; i++)
	{
		se = binarySearch(T[i], n);
		if( se == 1 ){ count++; }
	}
	printf("%d\n", count);
}
