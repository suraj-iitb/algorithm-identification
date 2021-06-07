#include<stdio.h>

#define N 100000

int binarySearch(int S[],int n,int T);

int main(void)
{
	int n,q,i,T,count=0;
	int S[N];
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(i=0; i<q; i++)
	{
		scanf("%d",&T);
		binarySearch(S,n,T);
		if(binarySearch(S,n,T)==1)
		{
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
	
int binarySearch(int S[],int n,int T)
{
	int mid,left=0;
	while(left<n)
	{
		mid=(left+n)/2;
		if(S[mid] == T)
		{
			return 1;
		}
		else if(T < S[mid])
		{
			n = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	return 0;
	
}
