#include<stdio.h>


#define N 100000

int linearSearch(int S[],int n,int T);

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
		linearSearch(S,n,T);
		if(linearSearch(S,n,T)==1)
		{
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
	
int linearSearch(int S[],int n,int T)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(S[i]==T)
		{
			return 1;
		}
	}
	return 0;
	
}
