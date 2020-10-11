#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int c[VMAX+1];
int i, j, n;

void CountingSort(int a[], int b[])
{
	for(i = 0; i <= VMAX; i++)
	{
		c[i] = 0;
	}
	
	for(j = 1; j <= n; j++)
	{
		c[a[j]]++;
	}
	
	for(i = 1; i <= VMAX; i++)
	{
		c[i] = c[i] + c[i-1];
	}
	
	for(j = n; j >= 1; j--)
	{
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
}

int main(void)
{
	scanf("%d", &n);
	
	int a[n];
	int b[MAX];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i+1]);
	}
	
	CountingSort(a, b);
	
	for(i = 1; i <= n; i++)
	{
		if(i > 1) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	
	return 0;
}
	
