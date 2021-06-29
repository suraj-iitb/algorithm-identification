#include<iostream>
#include<stdio.h>
using namespace std;
void trace(int A[], int N) {
	for (int i = 0;i < N;i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", A[i]);
	}
	cout << endl;
}
void insertSort(int A[], int N) {
	int v;
	for (int i = 1;i < N;i++) {
		v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}

int main() {
	int N;
	int A[100];
	cin >> N;
	for (int i = 0;i < N;i++)cin >> A[i];
	trace(A, N);
	insertSort(A, N);
	return 0;
}
