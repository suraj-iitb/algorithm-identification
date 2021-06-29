#include <bits/stdc++.h>
using namespace std;
int n, a[110];
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
			else break;
		}
		for(int j = 0; j < n; j++) {
			if(j>=1) cout << ' ';
			cout << a[j];
		}
		cout << endl;
	}
	return 0;
}

