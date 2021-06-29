#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
const int num = 2000001, num1 = 10000;
int main() {
	int n, a[num], c[num1 + 1], b[num];
	cin >> n;
	for (int i = 0; i <= num1; i++) c[i] = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) c[a[i]]++;
	for (int i = 1; i <= num1; i++) c[i] += c[i - 1];
	for (int i = 0; i < n; i++) b[(c[a[i]]--)-1] = a[i];
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << b[i];
	}
	cout << endl;
	return 0;
}
