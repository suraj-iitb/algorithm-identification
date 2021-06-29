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

	for (int i = 0; i < n; i++) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[minIdx] > a[j]) {
				minIdx = j;
			}
		}

		if (i != minIdx) {
			int tmp = a[i];
			a[i] = a[minIdx];
			a[minIdx] = tmp;
			count++;
		}
	}

	trace(a, n);
	cout << count << endl;

	return 0;
}

