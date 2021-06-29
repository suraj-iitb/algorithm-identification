#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int countn = 0;

void bubbleSort(int* a, int n) {
	int i, j;
	for ( i = 0; i < n - 1; i++) {
		for (j = n - 1; j >= i + 1; j--) {
			if (a[j-1] > a[j]) {
				swap(a[j-1], a[j]);
				countn++;
			}
		}
	}
}

int main() {

	int n;
	int a[110];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bubbleSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) cout << ' ';
	}
	cout << endl;
	cout << countn << endl;
}
