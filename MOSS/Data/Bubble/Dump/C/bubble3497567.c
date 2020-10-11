#include<stdio.h>
int main(void)
{
	int n;
	int a[100];
	int i,j,s;
	int c=0;
	int f=1;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(f==1)
	{
		f=0;
		for(j=n-1;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				s=a[j];
				a[j]=a[j-1];
				a[j-1]=s;
				c++;
				f=1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	printf("%d\n",c);
	return 0;
}
