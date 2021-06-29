#include<stdio.h>
#define N 100
int main()
{
	int n,b;
	scanf("%d",&n);
	int a[N];
	for(int c=0;c<n;c++)
	{
		scanf("%d",a+c);	
	}
	int numble=0,judge=1;
	while(judge)
	{
		judge=0;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
				numble++;
				judge=1;
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		printf("%d",a[j]);
		if(j!=n-1)
		{
			printf(" ");
		}

	}
	printf("\n");
	printf("%d",numble);
	printf("\n");
	return 0;
}
