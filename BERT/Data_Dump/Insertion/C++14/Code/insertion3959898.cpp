#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
#include<numeric>
#include<random>
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n;
	cin >> n;
	int v;
	int tmp;
	int a[1001];
	rep(i, n) {
		cin >> a[i];
	}
	rep(k, n) {
		if (k)cout << " ";
		cout << a[k];
	}
	cout << endl;
	for (int i = 1; i < n;i++) {

		v = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < v)break;
			tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
			}
		rep(k, n) {
			if (k)cout << " ";
			cout << a[k];
		}
		cout << endl;
	}
	return 0;
}
