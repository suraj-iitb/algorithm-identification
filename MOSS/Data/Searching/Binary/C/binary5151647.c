#include<stdio.h>
#define M 100000
#define N 50000

int binarySearch(int A[M],int key,int n)
{
	int left=0,right=n-1,x,i;
	
		
	while(right>=left)
	{
		x=(left+right)/2;
		if(A[x]==key)
		{
			return 1;
		}
		
		if(A[x]>key)
		{
			right=x-1;
		}
		else
		{
			left=x+1;
		}
	}
	
	return 0;
}
	

int linearSearch(int *A,int key,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]==key)
		{
			return 1;
		}
		
	}
	return 0;
}

int main(void)
{
	int i,k,q,n,s,t,j=0;
	int S[M],T[N];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(k=0;k<q;k++)
	{
		scanf("%d",&T[k]);
	}
	
	for(s=0;s<q;s++)
	{
			if(binarySearch(S,T[s],n)==1)
			{
				j++;
			}
	}
	printf("%d\n",j);
	
	return 0;
}
