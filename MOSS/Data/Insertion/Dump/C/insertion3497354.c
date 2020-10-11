#include<stdio.h>
int main(void)
{
	int n;
	int a[1000];
	int i,j;
	int v;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",a[j]);
			if(j!=n-1){
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
		
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v)
		{
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
	}
	for(j=0;j<n;j++)
	{
		printf("%d",a[j]);
		if(j!=n-1){
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
