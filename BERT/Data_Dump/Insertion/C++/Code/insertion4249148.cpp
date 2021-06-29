#include<iostream>
#include<cstdio>
#include<algorithm>
#include<time.h>
using namespace std;
int n;
int a[119];
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << a[i];
		if (i < n - 1) cout << ' ';
	}
	cout << endl;
	int j, i;
	for ( i = 1; i < n; i++) {
		j = i - 1;
		int k = a[i];
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
		int v;
		for (v = 0; v < n; v++) {
			cout << a[v];
			if (v < n - 1) cout << ' ';
		}

		cout << endl;
	}

}
