#include <stdio.h>

#define MNUM 100

int swap,arr[MNUM];

void Swap(int a,int b)
{
	int c=arr[a];
	arr[a]=arr[b];
	arr[b]=c;
	swap++;
}

int main()
{
	int num;
	swap=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<num;i++)
	{
		int minj=i;
		for(int j=i;j<num;j++)
		{
			if(arr[j]<arr[minj])
			{
				minj=j;
			}
		}
		if(i!=minj)Swap(i,minj);
	}
	
	for(int i=0;i<num;i++)
	{
		printf("%d",arr[i]);
		if(i!=num-1)printf(" ");
	}
	printf("\n%d\n",swap);
	
	return 0;
}
