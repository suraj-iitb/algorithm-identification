#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define ll long long

using namespace std;

int a[105];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
			cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl << cnt << endl;

	return 0;
}



