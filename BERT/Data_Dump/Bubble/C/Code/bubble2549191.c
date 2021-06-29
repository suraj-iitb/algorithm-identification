#include<stdio.h>

int main(void)
{
	int i,j,temp,A[100],n,count=0;
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
				count++;
			}
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
