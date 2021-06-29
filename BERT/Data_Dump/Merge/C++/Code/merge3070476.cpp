#include<stdio.h>

long long merge(long long[], int, int, int);
long long mergesort(long long[], int, int);

int main()
{
	int n;
	long long *s, count;
	scanf("%d", &n);
	s = new long long[n];
	for (int i = 0; i < n; i++)
		scanf("%d", s + i);
	count = mergesort(s, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%lld", s[i]);
	}
	printf("\n%lld\n", count);
	delete[] s;
	return 0;
}

long long merge(long long a[], int left, int mid, int right)
{
	int n1, n2, i = 0, j = 0;
	long long *l, *r;
	n1 = mid - left;
	n2 = right - mid;
	l = new long long[n1 + 1];
	r = new long long[n2 + 1];

	for (int i = 0; i < n1; i++)
		l[i] = a[left + i];
	for (int i = 0; i < n2; i++)
		r[i] = a[mid + i];
	r[n2] = l[n1] = 20000000000;
	for (int k = left; k < right; k++)
		if (l[i] <= r[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = r[j];
			j++;
		}

	delete[] l;
	delete[] r;
	return right - left;
}

long long mergesort(long long a[], int left, int right)
{
	long long count = 0;
	if (left + 1 < right)
	{
		int mid;
		mid = (left + right) / 2;
		count += mergesort(a, left, mid);
		count += mergesort(a, mid, right);
		count += merge(a, left, mid, right);
	}
	return count;
}
