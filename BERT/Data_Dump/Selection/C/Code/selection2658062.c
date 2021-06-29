#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int num,i,j,temp,min,count=0;
	scanf("%d",&num);
	int *p=(int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
	scanf("%d",&p[i]);
	for(i=0;i<num-1;i++)
	{
		min=i;
		for(j=i+1;j<num;j++)
		if(p[min]>p[j])
			min=j;
		if(min!=i)
		{
			temp=p[i];
			p[i]=p[min];
			p[min]=temp;
			count++;
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%d",p[i]);
		if(i+1!=num)
		printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}
