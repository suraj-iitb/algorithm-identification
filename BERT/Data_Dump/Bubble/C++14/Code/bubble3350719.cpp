#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				ans++;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << (i == n - 1 ? '\n' : ' ');
	cout << ans << endl;
}
