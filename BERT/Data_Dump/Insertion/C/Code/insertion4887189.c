#include<stdio.h>

int main(void)
{
	int i,j,v,N,c;
	
	scanf("%d",&N);
	
	int A[N];
	
	for(i=0;i<=N-1;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<=N-1;i++)
	{
		if(i<N-1)
		{
			printf("%d ",A[i]);
		}
		else
		{
			printf("%d\n",A[i]);
		}
	}
	for(i=1;i<=N-1;i++)
	{
		v = A[i];
		j = i - 1;
		
		while(j>=0 && A[j]>v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		for(c=0;c<=N-1;c++)
			{
				if(c<N-1)
				{
					printf("%d ",A[c]);
				}
				else
				{
					printf("%d\n",A[c]);
				}
			}
	}
	
	return 0;
}
