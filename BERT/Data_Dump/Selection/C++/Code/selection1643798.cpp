#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int i, j, n, mini, count = 0, a[100];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		mini = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[mini]) {
				mini = j;
			}
		}
		if (i != mini) {
			swap(a[i], a[mini]);
			count++;
		}
	}

	for (i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)cout << " ";
		else cout << endl;
	}
	cout << count << endl;

	return 0;
}
