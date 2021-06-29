#include<cstdio>
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

void trace(int N, int A[]) {
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i < N - 1)cout << " ";
	}
	cout << endl;
}

void insertSort(int N, int A[]) {
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(N, A);
	}
}

int main() {
	int N,i,j;
	cin >> N;
	int A[100];
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	trace(N, A);
	insertSort(N, A);
	return 0;
}
