#include<stdio.h>

int main(void){
	int N,i,j,k,a=0;
	scanf("%d",&N);
	int sort[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&sort[i]);
	}
	
	for(i=0;i<N;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(sort[j-1]>sort[j])
			{
				a=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=a;
			}
		}
		
		for(k=0;k<N-1;k++)
		{
			printf("%d ",sort[k]);
		}
		printf("%d",sort[N-1]);
		
		printf("\n");
	}
	
	return 0;
}
