#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n-1; i++) {
		cin >> a[i];
		cout << a[i] << ' ';
	}
	cin >> a[n - 1]; cout << a[n - 1];
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		cout << endl;
		for (int i = 0; i < n-1; i++)cout << a[i]<<' ';
		cout << a[n - 1];
	}
	cout<<endl;
}
