#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i,j,num,temp;
	scanf("%d",&num); 
	int *x=(int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
	scanf("%d",&x[i]);
	for(j=0;j<num;j++)
		{
			printf("%d",x[j]);
			if(j!=num-1)
			printf(" ");
		}
		printf("\n");
	for(i=1;i<num;i++)
	{
		j=i-1;
		temp=x[i];
		for(;j>=0&&x[j]>temp;j--)
			x[j+1]=x[j];
			x[j+1]=temp;
		for(j=0;j<num;j++)
		{
			printf("%d",x[j]);
			if(j!=num-1)
			printf(" ");
		}
		printf("\n");
		
	}
	return 0;
}
