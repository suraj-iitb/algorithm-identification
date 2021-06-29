#include <stdio.h>

int linearSearch(int a[],int n, int key);

int main(void)
{
	int n;
	scanf("%d",&n);
	int i;
	int s[n];
	for( i = 0; i < n; i++)
	{
		scanf("%d",&s[i]);
	}
	int q;
	scanf("%d",&q);
	int t[q];
	int j=0;
	
	for( i = 0; i < q; i++)
	{
		scanf("%d",&t[i]);
	}
	
	for( i = 0; i < q; i++)
	{
		j += linearSearch(s,n,t[i]);
		
	}
	printf("%d\n",j);
	return 0;
}

int linearSearch(int a[] , int n, int key)
{
	int i;
	for( i = 0; i < n; i++)
	{
		if(a[i] == key) return 1;
	}
	return 0;
}
