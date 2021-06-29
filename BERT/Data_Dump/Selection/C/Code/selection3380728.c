#include <stdio.h>
int main ()
{
	int min,i,j,n,a[100],temp,count;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i;j<n;j++)
			{
				if(a[min]>a[j])min=j;
			}
			if(min!=i)
			{
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
				count++;
			}
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1)printf("%d\n",a[i]);
			else
				printf("%d ",a[i]);
		}
		printf("%d\n",count);
	}
	return 0;
}
