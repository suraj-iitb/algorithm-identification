#include <iostream>
#include <vector>

using namespace std;

int slectionSort(vector<int> &A, int N) {
	int cnt=0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i+1; j < N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >>A[i];
	}
	int ans; ans = slectionSort(A, N);

	for (int i = 0; i < N - 1; i++) {
		cout << A[i] << " ";
	}
	cout <<A[N - 1] << endl;
	cout << ans << endl;
}
