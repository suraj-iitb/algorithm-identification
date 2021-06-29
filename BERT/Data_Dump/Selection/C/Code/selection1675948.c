#include<stdio.h>
int main()
{
	int i,j,n;
	int min_i;
	int temp;
	int a[100];
	int count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		min_i=i;
		for(j=i;j<n;j++)
		{
			if(a[j]<a[min_i])
				min_i=j;
		}
		if(min_i!=i)
		{
			temp=a[i];
			a[i]=a[min_i];
			a[min_i]=temp;
			count++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(i!=n-1)	
			printf("%d ",a[i]);
		else
			printf("%d\n",a[i]);
	}
	printf("%d\n",count);
	return 0;
}
