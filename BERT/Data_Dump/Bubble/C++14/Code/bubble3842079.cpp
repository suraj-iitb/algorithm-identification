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

int bs(int a[], int n) {
	int sw = 0;
	int i = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				sw++;
			}
		}
		i++;
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
	sw = bs(a, n);
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
