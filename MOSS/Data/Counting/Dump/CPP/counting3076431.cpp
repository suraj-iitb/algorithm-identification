#include<stdio.h>

int main()
{
	int n, *a, *b, c[10001];
	scanf("%d", &n);
	a = new int[n];
	b = new int[n];
	for (int i = 0; i < 10001; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		c[a[i]]++;
	}
	for (int i = 1; i < 10001; i++)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", b[i]);
	}
printf("\n");

	delete[] a;
	delete[] b;

	return 0;
}
