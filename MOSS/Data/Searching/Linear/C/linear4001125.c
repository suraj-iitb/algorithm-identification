#include<stdio.h>
int main()
{
	int i,j,n,q,c=0;
	int S[10000],T[10000];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
		for(i=0;i<n;i++)
		{
			if(S[i]==T[j])
			{
				c++;
				break;
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
				
