 
#include<stdio.h>
int main()
{
	int n,i,j,k,m,a[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==n-1)
				{
					printf("%d",a[j]);
				}
				else
				{
					printf("%d ",a[j]);
				}
			}
			printf("\n");
			for(m=i;m>=0;m--)
			{
				j=m+1;
				if(a[j]<a[m])
				{
					k=a[m];
					a[m]=a[j];
					a[j]=k;
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}
