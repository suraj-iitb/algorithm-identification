#include"bits/stdc++.h"
using namespace std;

void seiri(int a[], int n);

int main() {
	int a[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	seiri(a, n);
}

void seiri(int a[], int n) {
	int  v, j;
	for (int i = 0; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (int k = 0; k < n-1; k++) {
			cout << a[k] << ' ';
		}
		cout <<a[n-1]<< endl;
	}
}
