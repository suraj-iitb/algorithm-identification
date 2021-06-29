#include<iostream>

using namespace std;

int N;
const int MAX_N = 101;
int A[MAX_N];

void insertionSort(int A[], int N) {
	for (int i = 1; i < N; i++) {

		//途中経過出力
		for (int k = 0; k < N - 1; k++) {
			cout << A[k] << " ";
		}
		cout << A[N - 1] << endl;

		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
		
	}

	//答え
	for (int k = 0; k < N - 1; k++) {
		cout << A[k] << " ";
	}
	cout << A[N - 1] << endl;;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	insertionSort(A, N);

	return 0;
}
