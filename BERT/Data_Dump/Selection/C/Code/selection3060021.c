#include <stdio.h>

void print_array(int *a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
}

void scan_array(int *a, int *n)
{
	scanf("%d", n);
	for(int i = 0; i < *n; ++i)
	{
		scanf("%d", &a[i]);
	}
}

int main()
{
	int n, a[100];
	int cnt = 0;
	
	scan_array(a, &n);
	for(int i = 0; i < n; ++i)
	{
		int minj = i;
		for(int j = i + 1; j < n; ++j)
		{
			if(a[j] < a[minj])
			{
				minj = j;
			}
		}
		if(minj != i)
		{
			int temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;

			++cnt;
		}
	}

	print_array(a, n);
	printf("%d\n", cnt);
}

