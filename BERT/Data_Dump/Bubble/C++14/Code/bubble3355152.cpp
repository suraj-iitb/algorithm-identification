#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int flag = 1;
	int con = 0;

	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				con++;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << endl;
	cout << con << endl;
}
