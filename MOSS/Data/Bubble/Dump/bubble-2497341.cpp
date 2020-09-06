#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>
#include<utility>
#include<map>

using namespace std;

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int flag = 1,count =0;
	while (flag) {
		flag = 0;
		for (int i = n-1; i >0; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = 1;
				count++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0)cout << " ";
		cout << a[i];
	}
	cout << endl << count << endl;
	return 0;
}
