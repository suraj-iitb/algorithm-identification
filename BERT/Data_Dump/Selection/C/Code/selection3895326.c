#include<stdio.h>

int main(void){
	int N,i,j,a=0,c=0;
	scanf("%d",&N);
	int sort[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&sort[i]);
	}
	
	for(i=0;i<N-1;i++)
	{
		int min=i;
		for(j=i;j<N;j++)
		{
			if(sort[j]<sort[min])
			{
				min=j;
			}
		}
		
		if(sort[i]>sort[min])
		{
			a=sort[i];
			sort[i]=sort[min];
			sort[min]=a;
			c=c+1;
		}
		
	}
	
	for(i=0;i<N-1;i++)
	{
		printf("%d ",sort[i]);
	}
	printf("%d",sort[N-1]);
	printf("\n");
	printf("%d\n",c);
	
	return 0;
}
