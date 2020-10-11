#include <stdio.h>
#define max 10000

int main(void)
{
	int n;
	scanf("%d",&n);
	int i , k;
	int c[max];
	unsigned short *a , *b;
	a = malloc(sizeof(short)*n+1);
	b = malloc(sizeof(short)*n+1);

	scanf("%d",&a[0]);
	k = a[0];
	b[0] = 0;
	
	for( i = 1; i < n; i++)
	{
		scanf("%d",&a[i]);
		if(k < a[i])
		{
			k = a[i];
		}
		b[i] = 0;
	}
	
	for( i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	
	for( i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	
	for( i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i-1];
	}
	for( i = n; i >= 0; i--)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	for( i = 1; i <= n; i++)
	{
		if(i != n) printf("%d ",b[i]);
		else printf("%d\n",b[i]);
	}
	
	return 0;
}


