#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

void trace(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}

void insertionSort(int a[], int n) {
	trace(a, n);
	int v, j;
	for (int i = 1; i < n; i++) {
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

int main()
{
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	insertionSort(a, n);
}
