#include <cstdio>
#include <iostream>
using namespace std;

int selectionsort(int a[], int n)
{
	int i, j, t, sw = 0, minj;
	for (i = 0; i < n - 1; i++)
	{
		minj = i;
		for (j = i; j < n; j++)
		{
			if (a[j] < a[minj]) minj = j;
		}
		swap(a[i], a[minj]);
		if (i != minj) sw++;
	}
	return sw;
}

int main()
{
	int a[100], n, i, sw;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	sw = selectionsort(a, n);

	for (i = 0; i < n; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n%d\n", sw);

	return 0;
}
