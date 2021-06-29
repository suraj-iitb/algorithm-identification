#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, X[100];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	for (int i = 1; i <= N; i++) {
		sort(X, X + i);
		for (int i = 0; i < N; i++) {
			if (i != 0) cout << " ";
			cout << X[i];
		}
		cout << endl;
	}
}
