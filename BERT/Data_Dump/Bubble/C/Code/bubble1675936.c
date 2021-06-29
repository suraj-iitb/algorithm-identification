#include<stdio.h>
int main()
{
	int temp;
	int i,j,n;
	int a[100];
	int count=0;

	scanf("%d",&n);
	a[n]=9999;

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count++;
			}
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
