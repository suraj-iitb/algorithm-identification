#include<stdio.h>
#define N 100
int main()
{
	int n,b;
	scanf("%d",&n);
	int a[N];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);	
	}
	for(int j=1;j<n;j++)
	{
		for(int c=0;c<n;c++)
		{
			printf("%d",a[c]);
			if(c!=n-1)
			{
				printf(" ");
			}	
		}
		printf("\n");
		int numble;
		b=a[j];
		numble=j;
		while(numble>0&&b<a[numble-1])
		{
			a[numble]=a[numble-1];
			numble--;
		}
		a[numble]=b;
	}
	for(int c=0;c<n;c++)
		{
			printf("%d",a[c]);
			if(c!=n-1)
			{
				printf(" ");
			}	
		}
		printf("\n");
		return 0;
}
