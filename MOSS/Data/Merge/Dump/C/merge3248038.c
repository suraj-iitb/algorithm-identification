#include<stdio.h>
int a[500000], n, i;
int count = 0;

void  merge(int ar[], int left, int mid, int right)
{
	int n1, n2, L[500000], R[500000], i, j, k;
	n1 = mid - left;
	n2 = right - mid;

	for (i = 0; i < n1; i++)
		L[i] = ar[left + i];

	for (i = 0; i < n2; i++)
		R[i] = ar[mid + i];

	L[n1] = 1000000001;
	R[n2] = 1000000001;
	i = j = 0;

	for (k = left; k < right; k++)
	{
		if (L[i] <= R[j])
		{
			ar[k] = L[i];
			i++;
			count++;
		}
		else
		{
			ar[k] = R[j];
			j++;
			count++;
		}

	}
}

void mergesort(int ar[], int left, int right)
{
	int mid;
	if (left + 1 < right)
	{
		mid = (left + right) / 2;
		mergesort(ar, left, mid);
		mergesort(ar, mid, right);
		merge(ar, left, mid, right);
	}
}

int main()
{

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	mergesort(a, 0, n);

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			putchar(' ');
		printf("%d", a[i]);
	}

	printf("\n%d\n", count);

	return 0;
}
