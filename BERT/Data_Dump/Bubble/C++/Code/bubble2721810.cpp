#include <iostream>

using namespace std;

int N;
const int MAX_N = 100;
int A[MAX_N];

void bubbleSort(int A[], int N) {
	bool flag = 1;
	int cnt = 0;
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				int v = A[j - 1];
				A[j - 1] = A[j];
				A[j] = v;
				flag = 1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	cout << cnt << endl;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	bubbleSort(A, N);
	return 0;
}
