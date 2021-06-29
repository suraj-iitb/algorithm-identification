#include <stdio.h>

int main()
{
	int n, i, j, k, l;
	int a[1000];
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
	{
		k = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j--;
			a[j + 1] = k;
		}
		for (l = 0; l < n; l++)
		{
			printf("%d", a[l]);
			if (l != n - 1)
				putchar(' ');
		}
		putchar('\n');
	}


	return 0;
}
