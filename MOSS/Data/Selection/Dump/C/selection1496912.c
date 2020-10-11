#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	int i,j,k,temp;
	int *data;
	int count=0;
	
	scanf("%d",&N);
	data=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)scanf("%d",&data[i]);
	
	for(i=0;i<N;i++)
	{
		k=-1;
		int min=data[i];
		for(j=i;j<N;j++)
		{
			if(data[j]<min)
			{
				k=j;
				min=data[j];
			}
		}
		if(k!=-1)
		{
			count++;
			temp=data[k];
			data[k]=data[i];
			data[i]=temp;
		}
	}
	
	for(i=0;i<N-1;i++)printf("%d ",data[i]);
	printf("%d\n",data[N-1]);printf("%d\n",count);
	
	free(data);
	return 0;
}
