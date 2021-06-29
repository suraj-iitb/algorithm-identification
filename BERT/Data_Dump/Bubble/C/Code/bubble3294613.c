#include <stdio.h>
int main()
{
	int N,i,j,t,flag=0;
	int A[100];
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<N-1;i++)
	{
		for(j=N-1;j>i;j--)
		{
			if(A[j]<A[j-1])
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				flag++;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(i)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n%d\n",flag);
	return 0;
}
