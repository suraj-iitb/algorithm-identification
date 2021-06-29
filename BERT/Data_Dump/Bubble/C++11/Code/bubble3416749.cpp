#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int count = 0;
	int old_count = -1;
	cin >> n;
	vector<int>a;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		a.push_back(p);
	}
	while (count != old_count) {
		old_count = count;
		if (n == 1)break;
		for (int i = n - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				int k = a[i];
				a[i] = a[i - 1];
				a[i - 1] =k;
				count++;
			}
		}

	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)cout << " ";
	}cout << endl;
	cout << count << endl;
}

