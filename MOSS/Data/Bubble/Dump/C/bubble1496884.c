#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N,i,flag;
	int *data;
	int temp;
	int count=0;
	
	scanf("%d",&N);
	data=(int *)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++)scanf("%d",&data[i]);

	flag=1;
	while(flag)
	{
		flag=0;
		for(i=N-1;i>0;i--)
		{
			if(data[i]<data[i-1])
			{
				flag++;
				count++;
				temp=data[i];
				data[i]=data[i-1];
				data[i-1]=temp;
			}
		}
	}
	
	for(i=0;i<N-1;i++)printf("%d ",data[i]);
	printf("%d\n",data[N-1]);
	printf("%d\n",count);
	free(data);
	return 0;
}
