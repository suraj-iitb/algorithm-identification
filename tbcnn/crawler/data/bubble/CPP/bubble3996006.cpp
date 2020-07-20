#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define ll long long

using namespace std;

int a[108];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int cnt = 0;

	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = N - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				flag = 1;
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << a[i];
	}
	cout << endl << cnt << endl;



}


