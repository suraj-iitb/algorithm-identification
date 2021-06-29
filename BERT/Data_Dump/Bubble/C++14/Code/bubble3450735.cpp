#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (auto &a: arr) {
		cin >> a;
	}

	int swaps = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = N-1; j >= i+1; --j) {
			if (arr[j] < arr[j-1]) {
				swap(arr[j], arr[j-1]);
				++swaps;
			}
		}
	}

	cout << arr[0];
	for (int i = 1; i < N; ++i) {
		cout << ' ' << arr[i];
	}
	cout << '\n';

	cout << swaps << endl;
}
