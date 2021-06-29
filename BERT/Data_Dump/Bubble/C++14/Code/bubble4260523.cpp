#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, flag, ans = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num.at(i);
	}
	flag = 1;
	while (flag){
		flag = 0;
		for (int i = 1; i < n; i++) {
			if (num[i] < num[i - 1]) {
				swap(num[i], num[i - 1]);
				ans++;
				flag = 1;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		printf("%d", num.at(k));
		if (k != n - 1)cout << ' ';
		else cout << endl;
	}
	cout << ans << endl;
}
