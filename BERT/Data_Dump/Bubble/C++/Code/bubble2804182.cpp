#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main() {
	int n,a[101],flag,cnt=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	flag = 1;
	while (flag) {
		flag = 0;
		for (int i = n - 1; i > 0; --i) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i == n - 1)cout << a[i];
		else  cout << a[i] << " ";
	}
	cout <<endl<< cnt << endl;
	return 0;
}
