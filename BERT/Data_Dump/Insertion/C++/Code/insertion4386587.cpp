#include<iostream>
#include<cstdio>
#define n 100

using namespace std;

void insert(int A[], int N) {
	for (int i = 1; i < N; i++) {
		int t = A[i];
		int j = i - 1;
		while (j >= 0 && t < A[j]) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = t;

		for (int i = 0; i < N; i++) {
			cout << A[i];
			if(i != N -1) cout << " ";
		}
		cout << endl;
	}
}

int main() {
	int N, A[n];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for(int i = 0; i < N; i++){
	    cout << A[i];
	    if(i != N-1) cout << " ";
	}
	cout << endl;

	insert(A, N);

	return 0;
}
