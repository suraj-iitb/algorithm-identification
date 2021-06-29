#include <stdio.h>

void insertsort(int a[] , int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	int i,a[n];
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	insertsort(a,n);
	
	return 0;
}

void insertsort(int a[] , int n)
{
	int i , j , k , tmp;
	
	for(  k = 0; k < n; k++)
	{
		if(k != n-1)printf("%d ",a[k]);
		else printf("%d\n",a[k]);
	}

	for( i = 1; i < n; i++)
	{
		j = i;
		while( j > 0 && a[j] < a[j-1] )
		{
			tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
			j--;
		}
		for(  k = 0; k < n; k++)
		{
			if(k != n-1)printf("%d ",a[k]);
			else printf("%d\n",a[k]);
		}
	}
}
