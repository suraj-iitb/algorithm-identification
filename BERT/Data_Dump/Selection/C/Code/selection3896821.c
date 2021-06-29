#include<stdio.h>

int main(void)
{
	int n;
	
	scanf("%d",&n);
	
	int A[n];
	int i,j,minj,c=0,temp=0;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<n;i++)
	{
		minj=i;
		for(j=i;j<n;j++)
		{
			if(A[j]<A[minj])
			{
				minj=j;
			}
		}
		if(A[i]!=A[minj])
		{
			temp=A[i];
			A[i]=A[minj];
			A[minj]=temp;
			c++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(i>=1)
		{
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n");
	
	printf("%d\n",c);
	
	return 0;
}
