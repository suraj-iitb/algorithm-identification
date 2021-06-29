#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

void selectionSort(vector<int> v, int N);

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}

	selectionSort(v, N);
}

void selectionSort(vector<int> v, int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;

		for (int j = i; j < N; j++) {
			if (v.at(j) < v.at(minj)) minj = j;
		}

		if (i != minj) {
			int n = v.at(i);
			v.at(i) = v.at(minj);
			v.at(minj) = n;
			cnt++;
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
