#include <iostream>
#include <vector>
using namespace std;

int  bubleSort(int N, vector<int> &A) {
	int flag = 1;
	int cnt=0;
	while (flag) {
		flag = 0;
		for (int i = N-1; i>0; i--) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ans = bubleSort(N, A);

	for (int i = 0;i < N - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	cout << ans << endl;
}
