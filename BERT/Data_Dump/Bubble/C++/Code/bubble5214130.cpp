#include <iostream>
#include <vector>
using namespace std;

void trace (vector<int> a, int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << a.at(i);
	}
	cout << endl;
}

int main () {
	int n;
    cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}

	int count = 0;

	for (int c = 1; c < n; c++) {
		for (int i = n - 1; i >= c; i--) {
			if (a[i - 1] > a[i]) {
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				count++;
			}
		}
	}

	trace(a, n);
	cout << count << endl;

	return 0;
}

