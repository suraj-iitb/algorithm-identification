#include<stdio.h>
int main(void)
{
	int i,n,v,j,t;
	scanf("%d",&n);
	if(n>100)
	{
		return 0;
	}
	int A[n];
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&A[i]);
	}
	for (i=0;i<n;i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
			A[j+1]=v;
		
		for(t=0;t<=n-1;t++)
		{
			printf("%d",A[t]);
			
			if(t<n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
