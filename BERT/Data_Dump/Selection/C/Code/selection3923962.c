#include <stdio.h>
int main (void)
{
	int z,i,j,k,n,count, y;
	scanf("%d",&n);
	int x[n];
	count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++)
	{
		z=i;
		for(j=i;j<n;j++)
		{
			if(x[j]<x[z])
			{
				z=j;
			}
		}
		if(x[i]!=x[z])
		{
		y=x[i];
		x[i]=x[z];
		x[z]=y;
		count++;
		}
	}
	for(k=0;k<n;k++)
			{
				printf("%d",x[k]);
				if(k==n-1)
				{
					break;
				}
				printf(" ");
			}
			printf("\n");
		printf("%d",count);
		printf("\n");

}
