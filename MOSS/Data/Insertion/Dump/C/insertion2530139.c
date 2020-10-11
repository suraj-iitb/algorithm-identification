#include<stdio.h>
#define MAX 1000

int main(void)
{
	int R[MAX], n, i;

	// input
	scanf("%d", &n);
	for (i = 0; i < (n-1); i++)
	{
		scanf("%d", &R[i]);
		printf("%d ", R[i]);
	}
	scanf("%d", &R[i]);
	printf("%d\n", R[i]);

	// sort
	for (i = 1; i < n; i++)
	{
		int v = R[i];
		int j = i - 1;
		while ((j >= 0) && (R[j] > v))
		{
			R[j + 1] = R[j];
			j--;
		}
		R[j + 1] = v;
		int k;
		for (k = 0; k < (n - 1); k++)
		{
			printf("%d ", R[k]);
		}
		printf("%d\n", R[k]);
	}
}
