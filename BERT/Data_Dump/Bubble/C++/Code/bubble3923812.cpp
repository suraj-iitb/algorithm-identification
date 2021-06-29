#include <stdio.h>

int main(void)
{
	int N,i,j,t,c,A[100];
	
	scanf("%d",&N);
	
	for(i=0; i<N; i++)
	{
		scanf("%d",&A[i]);
	}
	c=0;
	
	for(i=0; i<N; i++)
	{
		for(j=N-1; j>=1; j--)
		{
			if(A[j]<A[j-1])
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				
				c++;
			}
		}
		
	}
    	
	for(i=0; i<N; i++)
	{
		printf("%d",A[i]);
		
		if(i!=N-1)
		{
			printf(" ");
		}
	}
	
    printf("\n");
    printf("%d\n",c);
	
	
    return 0;
}

