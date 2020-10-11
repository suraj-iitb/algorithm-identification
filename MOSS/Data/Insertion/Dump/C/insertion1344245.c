#include <stdio.h>

int main(void)
{
	int i,j,k;
	int buf;
	int num;
	int ary[100]={0};
	
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
	scanf("%d",&ary[i]);
	}
	
		for(k=0;k<num;k++)
	{
		printf("%d",ary[k]);
		if(k!=num-1)
		{
			printf(" ");
		}
	}
	
	printf("\n");
	
	for(i=1;i<num;i++)
	{
		buf = ary[i];
		j = i-1;
		while( (j>=0) && (ary[j]>buf) )
		{
			ary[j+1] = ary[j];
			j--;
		}
		ary[j+1]=buf;
		
		for(k=0;k<num;k++)
		{
			printf("%d",ary[k]);
			if(k!=num-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
