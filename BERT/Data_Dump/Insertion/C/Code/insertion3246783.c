#include<stdio.h>

int main(void)
{
	int i,j,k;
	int now;
	int N;
	scanf("%d",&N);
	int data[100];

	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}

	for(i=1;i<N;i++)
	{
		printf("%d",data[0]);
		for(j=1;j<N;j++)
		{
			printf(" %d",data[j]);
		}
		printf("\n");

		now=data[i];
		k=i-1;
		while((now<data[k])&&k>=0)
		{
			data[k+1]=data[k];
			k--;
		}
		data[k+1]=now;

	}
	printf("%d",data[0]);
	for(j=1;j<N;j++)
	{
		printf(" %d",data[j]);
	}
	printf("\n");


	return 0;
}
