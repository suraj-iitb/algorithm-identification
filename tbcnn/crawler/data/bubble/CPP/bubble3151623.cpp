#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#define ll long long
using namespace std;
const int wa=1e9+7;
int N, a[100];
int cnt = 0;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = N - 1; i > 0; i--) {
			if (a[i - 1] > a[i]) {
				int v = a[i];
				a[i] = a[i - 1];
				a[i - 1] = v;
				flag = 1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i];
		if (i != N - 1)cout << " ";
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}


