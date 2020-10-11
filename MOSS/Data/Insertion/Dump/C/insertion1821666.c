#include<stdio.h>

int main(void)
{
	int i,j,k,v,A[100],N;
	
	scanf("%d",&N);
	for(i=0;i<=N-1;i++)
	{
		scanf("%d",&A[i]);
		printf("%d",A[i]);
		if(i!=N-1) printf(" ");
	}
	for(i=1;i<=N-1;i++)
	{
		printf("\n");
		v=A[i];
		j=i-1;
		while(j >= 0 && A[j] > v)
		{
			A[j+1]=A[j];
			j--;
		}
	    A[j+1]=v;
		for(k=0;k<=N-1;k++)
		{
			printf("%d",A[k]);
			if(k!=N-1) printf(" ");
		}
	}
	printf("\n");
	return 0;
}
