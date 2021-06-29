#include<iostream>

using namespace std;

int bubblesort(int A[], int N) {
	bool flag = 1;
			int sw=0;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				sw++;
				flag = 1;
			}
		}

	}
	return sw;
}
int main() {
	int N, sw;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sw = bubblesort(A, N);
	for (int i = 0; i < N; i++) {
		if(i){cout <<" ";}
		cout << A[i];
	}
	cout << endl;
	cout << sw<<endl;
	return 0;
}
