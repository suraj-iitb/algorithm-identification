
#include <iostream>
//#include "std.h"

using namespace std;

int N;
int A[100];

void print(int *arr, int sz) {
	for (int i = 0; i < sz; ++i) {
		if (i == 0) cout << arr[i];
		else cout << " " << arr[i];
	}
	cout << endl;
}

void insert_sort() {
	print(A, N);
	for (int i = 1; i < N; ++i) {
		int k = A[i];
		int j = i-1;
		while (j >= 0 && A[j] > k) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = k;
		print(A, N);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	insert_sort();
	return 0;
}
