#include<stdio.h>

int main(void)
{
	int N,i,j=0,v=0,k;
	int a[100];
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{	
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<N;i++)
	{
		printf("%d",a[i]);
		if(i!=N-1){printf(" ");}
	}
	printf("\n");
	
	for(i=1;i<N;i++)
	{
		v=a[i];
		j=i-1;
		
		while(j>=0 && a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		
		for(k=0;k<N;k++)
		{
			printf("%d",a[k]);
			if(k!=N-1){printf(" ");}
		}
		printf("\n");
	}
		
	return 0;	
}
