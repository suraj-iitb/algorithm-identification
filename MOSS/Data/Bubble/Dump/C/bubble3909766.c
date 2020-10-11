#include<stdio.h>
int main(void)
{
	int n,i,j,tmp,count=0;
	scanf("%d",&n);
	int A[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(A[j]<A[j-1])
			{
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				count++;
			}
			
	
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

	return 0;
}
