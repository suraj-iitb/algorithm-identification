#include <stdio.h>

int main(void)
{
	int N,min,tmp;
	
	scanf("%d",&N);
	
	int a[N];
	
	for(int i=0; i<N;i++)
	{
		if(i==N-1)
		{
			scanf("%d",&a[i]);
		}
		else { scanf("%d ",&a[i]);}
	}
	
	int count = 0;
	for(int i=0;i<N;i++)
	{
		min = i;
		for(int j=i;j<N;j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		
		
			tmp =a[i];
			a[i]=a[min];
			a[min]=tmp;
			
		if (a[i] != a[min])
		{
			count++;
		}
		
	}
	
	for(int i=0;i<N;i++)
	{
		if(i==N-1)
		{
			printf("%d\n",a[i]);
		}
		
		else { printf("%d ",a[i]);}
	}
	
	printf("%d\n",count);
	
	return 0;
}
		
