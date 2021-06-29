#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[1000],i,j,v,k;
	for( i=0;i<n;i++ )
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++ )
	{
		if( i!=n-1 )
		{
				printf("%d ",a[i]);
		}
		else 	printf("%d",a[i]);
	}
	printf("\n");
	for( i=1;i<n;i++ )
	{
		v=a[i];
		j=i-1;
		while( j>=0 && a[j]>v )
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for( k=0;k<n;k++ )
		{
			if( k!=n-1 )
			{
				printf("%d ",a[k]);
			}
			else 	printf("%d",a[k]);
		}
		printf("\n");
	}
	return 0;
 } 
