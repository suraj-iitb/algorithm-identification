#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N) {
	int j, flag, counter;
	counter = 0;
	flag = 1;
	while (flag > 0) {
		flag = 0;
		for ( j = N - 1; j > 0; j--) {
			if (A[j] < A[j-1]) {
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
				counter++;
			}	
		}
	}

	return counter;
}

int main() {
	int N,  d, A[100];
	
	cin >> N;
	for ( int i = 0; i < N; i++) scanf("%d", &A[i]);
	
	d = bubbleSort(A, N);
		
	for ( int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	
	cout << endl;
	cout << d << endl;
	
	return 0;
}
