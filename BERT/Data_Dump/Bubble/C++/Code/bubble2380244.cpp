#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000;

int BubbleSort(int a[], int n)
{
	int i = 0, ans = 0;
	bool flag = 1;
	while (flag)
	{
		flag = 0;
		for (int j = n - 1; j >= i+1; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				ans++;
				flag = 1;
			}
		}
		i++;
	}
	return ans;
}

int main() {
	int n, i,ans;
	int A[N + 1];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	ans=BubbleSort(A, n);
	for (i = 0; i < n; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", ans);
	return 0;
}
