#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main() {
	bool judge;
	int n,a[101],flag,cnt=0,at;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		judge = false;
		at = i;
		for (int j = i; j < n; ++j) {
			if (a[j] < a[at]) {
				judge = true;
				at = j;
			}
		}
		if (judge) {
			swap(a[i], a[at]);
			cnt++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i == n - 1)cout << a[i] << endl;
		else
		cout << a[i] << " ";
	}
	cout << cnt << endl;
	return 0;
}
