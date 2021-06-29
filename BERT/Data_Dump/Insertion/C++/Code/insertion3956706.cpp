#include<iostream>
using namespace std;
int main(void)
{
	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int k = a[i];
		int flag = 0;
		for (int j = 0; j < i ; j++)
		{
			if (a[i] < a[j])
			{
				for (int m = i; m > j; m--) {
					a[m] = a[m - 1];
				}
				a[j] = k;
				break;
			}
		}
		for (int t = 0; t < n; t++) {
			if (t > 0) cout << " ";
			cout << a[t];
		}
		cout << endl;
	}
}
