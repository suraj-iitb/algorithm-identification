#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define ll long long

using namespace std;

int a[108];

int out(int N) {
	cout << a[0];
	for (int i = 1; i < N; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	out(N);

	for (int i = 1; i < N; i++) {
		int v = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] <= v) {
				break;
			}
			a[j + 1] = a[j];
			a[j] = v;
		}
		out(N);
	}
}


