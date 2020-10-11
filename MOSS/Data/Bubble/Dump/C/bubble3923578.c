#include <stdio.h>
int main (void)
{
	int z,i,j,k,n,count;
	scanf("%d",&n);
	int x[n];
	count=0;
	j=n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(x[j]<x[j-1])
			{
				z=x[j-1];
				x[j-1]=x[j];
				x[j]=z;
				count++;
			}
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
