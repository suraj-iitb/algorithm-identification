#include <stdio.h>

void print_array(int *a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
}

int main()
{
	int n, a[100];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	
	print_array(a, n);
	for(int i = 1; i < n; ++i)
	{
		int v = a[i];
		int j = i;
		while((j > 0) && (v < a[j-1]))
		{
			a[j] = a[j-1];
			--j;
		}
		a[j] = v;
		
		print_array(a, n);
	}
}

