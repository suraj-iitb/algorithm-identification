#include<stdio.h>

void t(int A[],int N)
{
	int i,j,k,v;
	
	for(i=1;i<N;i++)
	{
		v=A[i];
		j=i-1;
		
		while (j>=0&&A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0;k<N;k++)
		{
			if(k>0)
			{
				printf(" ");
			}
			printf("%d",A[k]);
		}
		printf("\n");
	}
}
int main(void)
{
	int N;
	
	scanf("%d",&N);
	
	int A[N];
	int i;
	int v,j;
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n");
	
	t(A,N);
}

