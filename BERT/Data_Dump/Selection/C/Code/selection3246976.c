#include<stdio.h>

int main(void)
{
	int i,j,N,minj,save;
	int count=0;
	scanf("%d",&N);
	int data[100];

	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}

	for(i=0;i<N;i++)
	{
		minj=i;
		for(j=i;j<N;j++)
		{
			if(data[j]<data[minj])
			minj=j;
		}
		if(i!=minj)
		{
			save=data[i];
			data[i]=data[minj];
			data[minj]=save;
			count++;
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
