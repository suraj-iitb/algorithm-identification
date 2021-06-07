#include<stdio.h>

int main(void)
{
	int n,i,q,j,c=0;
	
	scanf("%d",&n);
	
	int S[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	int T[q];
	
	for(i=0;i<q;i++)
	{
		scanf("%d",&T[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<q;j++)
		{
			if(S[i]==T[j])
			{
				c++;
				T[j] = -1;
			}
		}
	}
	
	printf("%d\n",c);
	return 0;
}
