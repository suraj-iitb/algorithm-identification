//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <cstdio>
#include<algorithm>
#include <utility>
using namespace std;
#define output for (int k = 0; k < n-1; k++) {cout << a[k] << " ";}cout << a[n - 1] << endl;
int main() {
	int n,v,j;
	vector<int> a(10000);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j>=0 && a[j]>v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		output;
	}
	return 0;
}
