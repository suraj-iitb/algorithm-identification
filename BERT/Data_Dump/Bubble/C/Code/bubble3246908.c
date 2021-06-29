#include<stdio.h>

int main(void)
{
	int i,flag,save,N;
	int count=0;
	scanf("%d",&N);
	int data[100];

	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}

	flag=1;

	while(flag)
	{
		flag=0;
		for(i=N-1;i>0;i--)
		{
			if(data[i]<data[i-1])
			{
				save=data[i];
				data[i]=data[i-1];
				data[i-1]=save;
				count++;
				flag=1;
			}
		}
	}
	
	printf("%d",data[0]);
	for(i=1;i<N;i++)
	{
		printf(" %d",data[i]);
	}
	printf("\n");
	printf("%d\n",count);


}
