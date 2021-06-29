#include <iostream>

using namespace std;

void selectionSort(int A[], int N) {
	int cnt = 0;
	for (int i = 0; i <= N - 1; i++) {
		bool flag = false;
		int minj = i;
			for (int j = i; j <= N - 1; j++) {
				if (A[j] < A[minj]) {
					minj = j;
					flag = true;
				}
			}
			if (flag) {
				int v = A[minj];
				A[minj] = A[i];
				A[i] = v;
				cnt++;
			}
			
	}
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			cout << A[i] << endl;
			break;
		}
		cout << A[i] << " ";
	}
	cout << cnt << endl;
}


int main() {
	int N;
	int A[100];
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	selectionSort(A, N);
	return 0;
}
