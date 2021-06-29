#include<stdio.h>

int main(void)
{
	int i,j,v,k,N;
	int A[100];
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++)
	{
     v = A[i];
     j = i - 1;
		
		while(j>=0&&A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0;k<N;k++)
		{
		    if (k < N-1) printf("%d ",A[k]);
		    else printf("%d", A[k]);
		}
		printf("\n");
	}
	return 0;
}

