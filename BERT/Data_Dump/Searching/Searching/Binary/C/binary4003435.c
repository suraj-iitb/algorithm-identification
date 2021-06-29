#include<stdio.h>

int binarysearch(int A[], int n, int key)
{
	int left, right, mid;
	
	left = 0;
	right = n;
	
	while(left < right)
	{
		mid = (left+right)/2;
		
		if(A[mid] == key)
		{
			return 1;
		}
		else if(key < A[mid])
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
		
	}
	return 0;
	
	
}

int main(void)
{

int n, q, count;



count = 0;

scanf("%d", &n);

int S[n];

for(int i=0; i<n; i++)
{
	scanf("%d", &S[i]);
}

scanf("%d", &q);

int T[q];
	
for(int i=0; i<q; i++)
{
	scanf("%d", &T[i]);
}

for(int i=0; i<q; i++)
{
	if( binarysearch(S,n,T[i])==1)
	{
		count++;
	}
}
	
	printf("%d\n", count);


return 0;

}
