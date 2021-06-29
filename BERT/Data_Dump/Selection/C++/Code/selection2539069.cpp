#include<iostream>
using namespace std;

class SelectionSort {
public:

	int sw = 0, minj, t,i,j;

	int Sort(int A[],int N) {
		for (i = 0; i < N; i++) {
			minj = i;
			for (j = i; j < N; j++) {
				if (A[j] < A[minj]) {
					minj = j;
				}
			}
			swap(A[i], A[minj]);
			if (i != minj) {
				sw++;
			}
		}
		return sw;
	}
};

int main() {
	int A[100], N,sw;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	SelectionSort ss;

	sw = ss.Sort(A, N);

	for (int i = 0; i < N; i++) {
			if (i) {
				cout << " ";
			}
			cout << A[i];
		}
	cout << endl;
	cout << sw;
	cout << endl;
}
