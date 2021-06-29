#include <iostream>
using namespace std;

int n;
int a[100];

int print(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
}

int insertionSort(int a[], int n) {
	print(a, n);

	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i -1;

		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		print(a, n);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insertionSort(a, n);
}
