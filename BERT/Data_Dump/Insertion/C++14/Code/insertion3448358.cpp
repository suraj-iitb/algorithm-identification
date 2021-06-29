#include <bits/stdc++.h>

using namespace std;

void print_vector(const vector<int> &v) {
	cout << v[0];
	for (auto i = 1u; i < v.size(); ++i) {
		cout << ' ' << v[i];
	}
	cout << '\n';
}

int main() {
	int N;
	cin >> N;
	
	vector<int> arr(N);
	for (auto &a: arr) {
		cin >> a;
	}

	print_vector(arr);
	for (int i = 1; i < N; ++i) {
		int current = arr[i];
		int j = i-1;
		for (; j >= 0 && current < arr[j]; --j) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = current;
		print_vector(arr);
	}
}
