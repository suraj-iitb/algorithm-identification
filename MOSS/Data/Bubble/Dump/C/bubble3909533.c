#include <stdio.h>

int main(void)
{
	int N,tmp;
	
	scanf("%d",&N);
	
	int a[N];
	for(int i=0;i<N;i++){
		if(i==N-1)
		{
			scanf("%d",&a[i]);
			
		}
		else {scanf("%d ",&a[i]);}
	}
	
	int count=0;
	
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				count++;
			}
		}
		
	}
	for(int i = 0; i<N;i++)
	{
		if(i==N-1)
		{
			printf("%d\n",a[i]);
		}
		else {printf("%d",a[i]);}
		
		if(i<N-1)
		{
			printf(" ");
		}
		
	}
	
	printf("%d\n",count);
	
	return 0;
}

