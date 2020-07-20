#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_ARRAY 100

void bubbleSort(int *R, int n) {
	bool flag = true;
	int count = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; 0 < j; j--) {
			if (R[j] < R[j - 1]) {
				int tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
				flag = true;
				count++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << ' ';
		}
		cout << R[i];
	}
	cout << endl <<  count << endl;
	return;
}

int main(void) {
	int n = 0, R[MAX_ARRAY] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> R[i];
	}

	bubbleSort(R, n);
	return 0;
}
