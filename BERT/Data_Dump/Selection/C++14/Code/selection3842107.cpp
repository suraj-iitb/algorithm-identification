#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int ss(int a[], int n) {
	int sw = 0;
	for (int i = 0; i < n-1; i++) {
		int minj = i;
		for (int j = i; j < n ; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		swap(a[i], a[minj]);
		if (i != minj) {
			sw++;
		}
	}
	return sw;
}

int main() {
	int a[100];
	int sw = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sw = ss(a, n);
	for (int i = 0; i < n; i++) {
		if (i) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}
