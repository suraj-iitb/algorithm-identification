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
		for (int i = 0; i < N; i++) {
			int minj = i;
			for (int j=i; j < N; j++) {
				if (a[j] < a[minj]) {
					minj = j;
				}
			}
			if (minj != i) {
				swap(a[i], a[minj]);
				cnt++;
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


