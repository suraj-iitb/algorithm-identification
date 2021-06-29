#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a[100],cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << cnt << endl;
}
