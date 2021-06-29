#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_ARRAY 100
int main(void) {
	int n = 0, a[MAX_ARRAY];
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	for (int k = 0; k < n - 1; k++) {
		cout << a[k] << ' ';
	}
	cout << a[n - 1] << endl;


	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (int k = 0; k < n-1; k++) {
			cout << a[k] << ' ';
		}
		cout << a[n-1] << endl;
	}


	return 0;
}
