#include<stdio.h>
#define N 100
void output(int* a,int numble,int n);

int main()
{
	int n,b;
	scanf("%d",&n);
	int a[N];
	for(int c=0;c<n;c++)
	{
		scanf("%d",a+c);	
	}
	int numble=0;
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int d=i+1;d<n;d++)
		{
			if(a[min]>a[d])
			{
				min=d;
			}
		}
		if(a[min]!=a[i])
		{
			b=a[min];
			a[min]=a[i];
			a[i]=b;
			numble++;
		}
	}
	output(a,numble,n);
	return 0;
}
void output(int* a,int numble,int n)
{
	for(int j=0;j<n;j++)
	{
		if(j!=0)
		{
			printf(" ");
		}
		printf("%d",*(a+j));
		
	}
	printf("\n%d",numble);
	printf("\n");
}
