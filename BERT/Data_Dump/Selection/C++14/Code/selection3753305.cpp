#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int minj;
	int counter = 0;
	for (int i = 0; i < n ; i++) {
		minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		swap(a[i], a[minj]);
		if (minj != i) { counter++; }
	}

	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << counter << endl;
}
