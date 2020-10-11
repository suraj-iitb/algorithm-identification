#include<stdio.h>

int main(void)
{
	int i,j,n,A[100],min,temp,count=0;
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		min=i;
		for(j=i;j<=n-1;j++)
		{
			if(A[min]>A[j])
			{
				min=j;
			}
		}
		if(i!=min)
		{
		   temp=A[min];
		   A[min]=A[i];
		   A[i]=temp;
		   count++;
		}
	}
	printf("%d",A[0]);
	for(i=1;i<=n-1;i++)
	{
		printf(" %d",A[i]);
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}
