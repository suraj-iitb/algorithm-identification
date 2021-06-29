#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0 ; i < N; i++) {
		cin >> A[i];
	}
	int temp, j;
	for (int i = 0; i < N; i++) {
		temp = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > temp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
		for (int j = 0; j < N; j++) {
			if (j != N - 1) {
				cout << A[j] << " " << flush;
			}
			else {
				cout << A[j] << endl;
			}
		}

	}
	return 0;
}
