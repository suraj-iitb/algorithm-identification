#include <stdio.h>

int ssort(int a[] , int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i , count = 0;
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	count = ssort(a,n);
	
	for( i = 0; i < n; i++)
	{
		if( i != n-1)printf("%d ",a[i]);
		else printf("%d\n",a[i]);
	}
	printf("%d\n",count);
	return 0;
}

int ssort(int a[] , int n)
{
	int i , j , min , tmp , count = 0;
	for( i = 0; i < n; i++)
	{
		min = i;
		for( j = i; j < n; j++)
		{
			if(a[j] < a[min]) min = j;
		}
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
		if( i != min) count++;
	}
	return count;
}
