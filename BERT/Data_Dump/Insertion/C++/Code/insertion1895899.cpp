#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int a[100], n, j, v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		cout << a[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}

	

	for (int i = 1; i < n; i++) {
		j = i - 1;
		v = a[i];

		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];

			a[j] = v;

			j--;
		}


		for (int i = 0; i < n; i++) {
			cout << a[i];

			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	return 0;
}
