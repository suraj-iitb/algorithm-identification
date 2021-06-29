#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bool flag = true;
	int cnt = 0;
	while (flag) {
		flag = false;

		for (int i = n - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = true;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			printf("%d ", a[i]);
		}
		else {
			printf("%d\n", a[i]);
		}
	}
	cout << cnt << endl;
	
	return 0;
}
