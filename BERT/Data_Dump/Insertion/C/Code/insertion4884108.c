#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;//要素の個数
	int *A;//数列A
	
	scanf("%d",&N);
	A=(int *)malloc(sizeof(int)*N);
	
	int i;
	for(i=0; i<N; i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",A[i]);//初期配列
	}
	printf("\n");
	
	int x,j;
	for(i=1;i<N;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(A[j]>A[j+1])
			{
				x=A[j+1];
				A[j+1]=A[j];
				A[j]=x;
			}
		}
		
		for(j=0;j<N;j++)
		{
			if(j!=0)
			{
				printf(" ");
			}
			printf("%d",A[j]);//各ステップ終了後の配列
		}
		printf("\n");
	}
	free(A);
	A=NULL;
	
	return 0;
}
