#include<iostream>
using namespace std;
int selection(int a[], int n)
{
	int sw = 0;
	for (int i = 0; i < n - 1; i++) {
		int minj = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[j] < a[minj])
			{
				minj = j;
			}
		}
		swap(a[i], a[minj]);
		if (i != minj)sw++;
	}
	return sw;
}
int main()
{
	int a[100], n, sw;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sw = selection(a, n);
	for (int i = 0; i < n; i++)
	{
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}
