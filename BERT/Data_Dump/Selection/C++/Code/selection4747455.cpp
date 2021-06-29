#include <bits/stdc++.h>
using namespace std;

int selectSort(int A[], int N) {
	int minj, counter, temp;
	counter = 0;
	for (int j = 0 ; j < N-1; j++) {
	minj = j;
		for (int i = j + 1; i < N; i++) {
			if (A[i] < A[minj]) {
				minj = i;	
			}
		}
		if (minj != j) {
			temp = A[j];
			A[j] = A[minj];
			A[minj] = temp;
			counter++;
		} else {
			continue;
		}
		
	}
	return counter;
}


int main() {
	int N, counter, A[100];
	
	cin >> N;
	for ( int i = 0; i < N; i++) scanf("%d", &A[i]);
	
	counter = selectSort(A, N);
		
	for ( int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	
	cout << endl;
	cout << counter << endl;
	
	return 0;
}
