#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

void bubbleSort(vector<int> v, int N);

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}

	bubbleSort(v, N);
}

void bubbleSort(vector<int> v, int N) {
	int f = 1;
	int cnt = 0;
	while (f) {
		f = 0;
		for (int i = N - 1; i > 0; i--) {
			if (v.at(i) < v.at(i - 1)) {
				int n = v.at(i);
				v.at(i) = v.at(i - 1);
				v.at(i - 1) = n;
				cnt++;
				f = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << v.at(i);
		if (i == N - 1) {
			cout << endl;
			cout << cnt << endl;
		}
		else {
			cout << ' ';
		}
	}
}
