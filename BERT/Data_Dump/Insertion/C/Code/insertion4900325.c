#include<stdio.h>
#define MAX_N 100

int main(void)
{
	int i,j,n,v;
	int A[MAX_N];
	//printf("N:");
	scanf("%d",&n);
	//printf("Aの整数:");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d", A[j]);
			if(j<n-1)
			{
				printf(" ");
			}
		}
		v =A[i];
		j=i-1;
		printf("\n");
		while (j>=0&&A[j]>v)
		{
			A[j+1]=A[j];
			j--;
			A[j+1]=v;
		}
	}
	return 0;
}
