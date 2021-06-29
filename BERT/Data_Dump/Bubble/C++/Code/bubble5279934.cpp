#include <iostream>
#include <algorithm>
using namespace std;
void sort(int* a, int n,int *count)
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = n - 1;i >= 1;i--)
			if (a[i] < a[i - 1])
			{
				int t;
				t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				flag = 1;
				(*count)++;
			}
	}
}
#include <cstdio>
int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int count = { 0 };
	sort(a, n,&count);
	for (int i = 0;i < n;i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", a[i]);
	}
	cout << "\n" <<count <<endl;
}
