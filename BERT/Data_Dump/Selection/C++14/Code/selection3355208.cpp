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

	int con = 0;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
		if (min != i) {
			con++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i)  cout << ' ';
		cout << a[i];
	}
	cout << endl;

	cout << con << endl;
}
