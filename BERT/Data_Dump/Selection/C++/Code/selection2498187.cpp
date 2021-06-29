#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_ARRAY 100

int selectSort(int *a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		if (i != min_idx) {
			swap(a[i], a[min_idx]);
			count++;
		}
	}

	return count;
}


int main(void) {
	int n = 0, R[MAX_ARRAY] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> R[i];
	}

	int sc = selectSort(R, n);
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << ' ';
		}
		cout << R[i];
	}
	cout << endl << sc << endl;
	return 0;
}
