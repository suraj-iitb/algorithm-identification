#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cout << a[0];
		for (int k = 1; k < n; k++) {
			cout << " " << a[k];
		}
		cout << endl;
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
	cout << a[0];
	for (int k = 1; k < n; k++) {
		cout << " " << a[k];
	}
	cout << endl;
	delete[] a;
	return 0;
}
