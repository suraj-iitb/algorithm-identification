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
	int loop = 1, cnt = 0;;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	while(loop)
	{
		loop = 0;
		for(int i = n - 1; i > 0; --i)
		{
			if(a[i] < a[i-1])
			{
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;

				++cnt;
				loop = 1;
			}
		}
	}
	print_array(a, n);
	printf("%d\n", cnt);
}

