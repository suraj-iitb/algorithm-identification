#include<cstdio>
#include<iostream>
 
using namespace std;

int bubleSort(int a[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n-1; j>=i+1; --j)
		{
			if (a[j-1] > a[j])
			{
				swap(a[j-1], a[j]);
				cnt++;
			}
		}
	}
	return cnt;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void solve()
{
	int n;
	int a[105];
	cin >> n;
	for (int i = 0; i<n; ++i) cin >> a[i];
	int ans = bubleSort(a, n);
	for (int i = 0; i < n-1; ++i) printf("%d ", a[i]);
	printf("%d", a[n - 1]);
	printf("\n");
	printf("%d\n", ans);
}
int main()
{
	solve();
	return 0;
}
