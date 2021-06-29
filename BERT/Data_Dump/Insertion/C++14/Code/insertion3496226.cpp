#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	for (int i = 0; i < N; ++i) {
		int j, tmp = A[i];
		for (j = i - 1; A[j] > tmp && j >= 0; --j) A[j + 1] = A[j];
		A[j + 1] = tmp;
		for (j = 0; j < N - 1; ++j) cout << A[j] << ' ';
		cout << A[N - 1] << endl;
	}
}
