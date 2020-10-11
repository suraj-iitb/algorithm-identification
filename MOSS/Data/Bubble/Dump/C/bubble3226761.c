#include <stdio.h>

int main()
{
	int n, i, j, temp, flag;
	int a[1000];

	j = 0;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	flag = 1;
	while (flag)
	{
		flag = 0;
		for (i = n - 1; i >= 1; i--)
		{
			if (a[i] < a[i - 1])
			{
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				flag = 1;
				j++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
			putchar(' ');
	}
	putchar('\n');

	printf("%d\n", j);

	return 0;
}
