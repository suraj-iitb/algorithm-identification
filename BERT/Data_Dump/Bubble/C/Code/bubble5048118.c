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
	
	int flag=1;
	while(flag)
	{
		flag=0;
		for(int j=num-1;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			{
				Swap(j,j-1);
				flag=1;
			}
		}
	}
	
	for(int i=0;i<num;i++)
	{
		printf("%d",arr[i]);
		if(i!=num-1)printf(" ");
	}
	printf("\n%d\n",swap);
	
	return 0;
}
