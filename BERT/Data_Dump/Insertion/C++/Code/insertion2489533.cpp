#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void show(int *A,int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}


void trace(int *A, int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}


//void insertSort(int *A,int n) {
//	int t;
//	for (int i = 1; i < n; i++) {
//		int j = i;
//		while (A[j - 1] > A[j]) {
//			t = A[j];
//			A[j] = A[j - 1];
//			A[j - 1] = t;
//			j--;
//		}
//		show(A, n);
//	}
//}

void insertSort(int A[], int N) {
	int j, i, v;
	for (i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}

int main() {
	int n, A[1000];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	trace(A, n);
	insertSort(A,n);

	return 0;
}
