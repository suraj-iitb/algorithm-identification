#include<stdio.h>

int main(void)
{
	int i;
	
	int n;
	scanf("%d",&n);
	
	int S[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	int q;
	scanf("%d",&q);
	
	int T[q];
	for(i=0;i<n;i++)
	{
		scanf("%d",&T[i]);
	}
	
	int x=0,count=0;
	for(i=0;i<q;i++)
	{
		x=T[i];
		for(int j=0;j<n;j++)
		{
			if(x==S[j])
			{
				count++;
				break;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
