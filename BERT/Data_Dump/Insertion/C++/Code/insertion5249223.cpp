#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100100;
int n, a[MAXN];

void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int i = 0; i < n; i++)
			if (i != n - 1)
				cout << a[i] << " ";
			else
				cout << a[i] << endl;
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	InsertionSort(a, n);
	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << a[i] << " ";
		else
			cout << a[i] << endl;

	return 0;
}
