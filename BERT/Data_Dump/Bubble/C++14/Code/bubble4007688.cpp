#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int>& A, int N) {
	bool flag = true;
	int count = 0;
	int i = 0;
	while (flag) {
		flag = false;
		for (int j = N-1; j > i; j--) {
			if (A[j-1] > A[j]) {
				int tmp = A[j-1];
				A[j-1] = A[j];
				A[j] = tmp;
				flag = true;
				count++;
			}
		}
		i++;
	}
	return count;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	int cnt = bubbleSort(A, N);
	for (int i = 0; i < N; i++) {
		if (i == N-1) cout << A[i] << endl;
		else cout << A[i] << ' ';
	}
	cout << cnt << endl;
}

