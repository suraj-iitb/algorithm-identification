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

void selectionSort(int a[], int n) {
	int j, minJ, c = 0;
	for (int i = 0; i < n; i++) {
		minJ = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minJ]) {
				minJ = j;
			}
		}
		if (i != minJ) {
			swap(a[i], a[minJ]);
			c++;
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

	selectionSort(a, n);
}
