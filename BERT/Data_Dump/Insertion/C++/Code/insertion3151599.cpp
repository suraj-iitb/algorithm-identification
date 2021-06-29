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
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < N; i++) {
		for (int i = 0; i < N; i++) {
			cout << a[i];
			if(i != N - 1)cout<< " ";
		}
		cout << endl;
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}

	}
	for (int i = 0; i < N; i++) {
		cout << a[i];
		if(i!=N-1)cout<<" ";
	}
	cout << endl;
	return 0;
}
