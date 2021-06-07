#include<stdio.h>

int a[100001];
int n, sum = 0;

int binarySearch(int x)
{
	int low, high, mid;
	low = 0, high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < a[mid])
			high = mid - 1;
		else if (x > a[mid])
			low = mid + 1;
		else return 1;
	}
	return 0;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		if (binarySearch(x))
			sum++;
	}
	printf("%d\n", sum);
}

int main()
{
	solve();
}
