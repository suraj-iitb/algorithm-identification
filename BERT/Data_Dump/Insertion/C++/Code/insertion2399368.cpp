#include <iostream>

using namespace std;

int main()
{
	int n;
	int a[1000];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int v = a[i];
		int j;
		for (j = i - 1; j > 0 && a[j] > v; j--)
			a[j + 1] = a[j];
		a[j + 1] = v;
		
		for (int i = 1; i < n; i++)
			cout << a[i] << ' ';
		cout << a[n] << endl;
	}
}
