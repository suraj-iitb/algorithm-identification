#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

void insertionSort(vector<int> v, int N);

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);

		cout << v.at(i);
		if (i == N - 1) {
			cout << endl;
		}
		else {
			cout << ' ';
		}
	}

	insertionSort(v, N);
}

void insertionSort(vector<int> v, int N) {
	for (int i = 1; i < N; i++) {
		int n = v.at(i);
		int j = i - 1;

		while (j >= 0 && v.at(j) > n) {
			v.at(j + 1) = v.at(j);
			j--;
		}
		v.at(j + 1) = n;

		for (int k = 0; k < N; k++) {
			cout << v.at(k);
			if (k == N - 1) {
				cout << endl;
			}
			else {
				cout << ' ';
			}
		}
	}
}
