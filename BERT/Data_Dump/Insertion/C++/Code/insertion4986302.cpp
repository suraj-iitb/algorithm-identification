#include<iostream>
using namespace std;

void trace(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i > 0)
			cout << " ";
		cout << a[i];
	}
	cout << endl;
}

void insertionSort(int a[], int n) {
	int j, i, v;
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		trace(a, n);
	}
}
int main() {
	int n, i, j;
	int a[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	trace(a, n);
	insertionSort(a, n);
	return 0;
}
