#include<stdio.h>
int main(void)
{
	int n,i,j,minj,tmp;
	int count=0;
	scanf("%d",&n);
	
	int A[n];
	
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
				tmp=A[i];
				A[i]=A[minj];
				A[minj]=tmp;
		if(i!=minj)
		{
				count++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d",A[i]);
		if(i!=n-1)
		{
		printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
}

