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
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			int k = a[i];
			a[i] = a[minj];
			a[minj] = k;
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)cout << " ";
	}cout << endl;
	cout << count << endl;
}



