#include <iostream>
using namespace std;
void trace(int A[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0)  cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int bubbleSort(int A[], int N) {
	int j, i,t=0,num=0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i-1; j++) {
			if (A[j] > A[j + 1]) { t = A[j]; A[j] = A[j + 1]; A[j + 1] = t; num++; }
		}
		
	}
	return num;
}
int main() {
	int N, i, j;
	int A[100] = {0};
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
	int n= bubbleSort(A, N);
	trace(A, N);
	cout << n << endl;
	return 0;
}
