#include <iostream>
using namespace std;

int main()
{
	int n = 0, a[100] = { 0 }, v = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {

		int j = 0;

		v = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			a[j] = v;
			j--;
		}

		for (int k = 0; k < n - 1; k++)
			cout << a[k] << " ";

		cout << a[n - 1] << endl;
	}

		
	return 0;
}
