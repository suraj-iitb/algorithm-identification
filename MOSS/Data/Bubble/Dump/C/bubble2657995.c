#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int num,i,j,temp,flag=1,count=0;
	scanf("%d",&num);
	int *p=(int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
	scanf("%d",&p[i]);
	i=num-1;
	while(i>0&&flag==1)
	{
		flag=0;
		for(j=0;j<i;j++)
		if(p[j]>p[j+1])
		{
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			count++;
			flag=1;		
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
