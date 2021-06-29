#include<bits/stdc++.h>
using namespace std;

void printarray(int A[], int len) {
	for (int i = 0; i < len - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[len - 1] << endl;
}

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i < N; i++) {
		printarray(A, N);
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
	printarray(A, N);
	return 0;
}

