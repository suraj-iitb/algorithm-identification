#include<bits/stdc++.h>
using namespace std;


int main() {

	int n; cin >> n;
	int a[100]; for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = n - 1; i > 0; i--) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				ans++;
				flag = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << a[i];
	}
	cout << endl;

	cout << ans << endl;

	return 0;
}



