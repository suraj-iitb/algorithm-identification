#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<functional>
using namespace std;

signed main() {
	int a; cin >> a;
	int b[100];
	for (int c = 0; c < a; c++)cin >> b[c];
	int sum = 0;
	for (int c = 0; c < a - 1; c++) {
		int MIN = b[c],n=c;
		for (int d = c + 1; d < a; d++) {
			if (b[d] < MIN) {
				MIN = b[d]; n = d;
			}
		}
		if (n == c)continue;
		swap(b[c], b[n]);
		sum++;
	}
	for (int i = 0; i < a; i++) {
		if (i)cout << " ";
		cout << b[i];
	}
	cout <<endl<< sum << endl;
}
