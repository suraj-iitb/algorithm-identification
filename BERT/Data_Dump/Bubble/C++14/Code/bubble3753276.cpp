#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool gflag = true;
	int counter = 0;
	while (gflag) {
		gflag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				gflag = 1;
				counter++;
			}
		}
	}
	for (int i = 0; i < n-1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << counter << endl;
}
