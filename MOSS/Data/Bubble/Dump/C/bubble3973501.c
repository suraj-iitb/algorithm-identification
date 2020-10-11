#include <stdio.h>

int bsort(int a[] , int n);

int main(void)
{
	int n , count , i;
	scanf("%d",&n);
	int a[n];
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	count = bsort(a,n);
	for( i = 0; i < n; i++)
	{
		if( i != n-1)printf("%d ",a[i]);
		else printf("%d\n",a[i]);
	}
	printf("%d\n",count);
	return 0;
}

int bsort(int a[] , int n)
{
	int i , j , tmp , count = 0;
	for( i = 0; i < n; i++)
	{
		for( j = n-1; j > i; j--)
		{
			if(a[j] < a[j-1])
			{
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				count++;
			}
		}
	}
	
	return count;
}
