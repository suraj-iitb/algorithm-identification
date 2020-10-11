#include<stdio.h>

int main(void)
{
	int n;
	
	scanf("%d",&n);
	
	int A[n];
	int i,j,temp=0,c=0;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(A[j]<A[j-1])
			{
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
				c++;
			}
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
