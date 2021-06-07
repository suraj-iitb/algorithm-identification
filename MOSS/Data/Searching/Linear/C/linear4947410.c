#include<stdio.h>
#define M 10000
#define N 500

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
			if(linearSearch(S,T[s],n)==1)
			{
				j++;
			}
	}
	printf("%d\n",j);
	
	return 0;
}

