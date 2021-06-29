#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a, ans = 0; cin >> n;
	int test[101] = { 0 };
	for (int h = 0; h < n; h++) {
		cin >> a;
		test[h] = a;
	}
	for (int h = 0; h < n - 1; h++) {
		for (int i = n - 1; i > 0; i--) {
			if (test[i - 1] > test[i]) {
				int uio = test[i];
				test[i] = test[i - 1];
				test[i - 1] = uio;
				ans++;
			}
		}
	}
	for (int h = 0; h < n; h++) {
		cout << test[h];
		if (h != n - 1) {
			cout << ' ';
		}
	}
	cout << endl; cout << ans << endl;
	cin >> n;
}
