#include <stdio.h>

#define NUM_MAXNUM 100

int arr[NUM_MAXNUM];
int num_num;

void Printer()
{
	for(int i=0;i<num_num;i++)
	{
		printf("%d",arr[i]);
		if(i+1!=num_num)printf(" ");
	}
	printf("\n");
}

int main()
{
	scanf("%d",&num_num);
	for(int i=0;i<num_num;i++)
	{
		if(scanf("%d",&arr[i])==EOF)break;
	}
	
	for(int i=0;i<num_num;i++)
	{
		int v=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>v)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=v;
		Printer();
	}
	
	return 0;
}
