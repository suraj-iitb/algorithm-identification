#include<stdio.h>

int main(void)
{
	int n,q,i,j,S[10000],T[500],count=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
	}
	
	for(j=0;j<q;j++)
	{
		for(i=0;i<n;i++)
		{
			if(S[i]==T[j])
			{
				count++;;
				break;
			}
		}
	}
	printf("%d\n",count);
	
	return 0;
}