#include<stdio.h>

int main(void)
{
	int i,j,t,a[100],n,count=0;
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
				count++;
			}
		}
	}
	printf("%d",a[0]);
	for(i=1;i<=n-1;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}
