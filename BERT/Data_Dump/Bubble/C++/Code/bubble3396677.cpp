#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void prints(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}

void bubbleSort(int a[], int n) {
	int c = 0;
	bool f = true;
	while (f) {
		f = false;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				c++;
				f = true;
			}
		}
	}

	prints(a, n);
	cout << c << "\n";
}

int main()
{
	int n, a[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	bubbleSort(a, n);
}
