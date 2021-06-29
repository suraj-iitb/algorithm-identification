#include <stdio.h>
int main(void)
{
	int A[100],minj,t,i,j,c,N;
	
	scanf("%d",&N);
	
	for(i=0; i<N; i++)
	{
		scanf("%d",&A[i]);
	}
	
	c=0;
	
	for(i=0; i<N; i++)
	{
		minj=i; //最小値が入っているものをA[minj]とする
		
		for(j=i; j<N; j++)
		{
			if(A[j]<A[minj])
			{
				minj=j;
			}
		}
		
		
		
		if(i!=minj)
		{
			t=A[i];
			A[i]=A[minj];
			A[minj]=t;
			c++;
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


