#include<stdio.h>
#include<stdlib.h>

void insert(int src[],int num)
{
	int i,k;
	for(i=1;i<num;i++)
	{
		int v=src[i];
		int j=i-1;
		while(j>=0&&src[j]>v)
		{
			src[j+1]=src[j];
			j--;
		}
		src[j+1]=v;
		for(k=0;k<num-1;k++)printf("%d ",src[k]);
		printf("%d\n",src[num-1]);
	}
}

int main()
{
	int N,i;
	int *data;
	scanf("%d",&N);
	data=(int *)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++)scanf("%d",&data[i]);
	
	for(i=0;i<N-1;i++)printf("%d ",data[i]);
	printf("%d\n",data[N-1]);
	insert(data,N);
	
	free(data);
	return 0;
}
