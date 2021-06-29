#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N, ans = 0;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = N - 1; j > i; --j) {
			if (A[j - 1] > A[j]) {
				++ans;
				swap(A[j - 1], A[j]);
			}
		}
	}
	for (int i = 0; i < N - 1; ++i) cout << A[i] << ' ';
	cout << A[N - 1] << endl << ans << endl;
}
