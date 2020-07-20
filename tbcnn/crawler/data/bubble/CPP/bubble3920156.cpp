#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	int sum = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j > i; j--) {
			if (V[j - 1] > V[j]) {
				swap(V[j], V[j - 1]);
				sum++;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << V[i];
		if (i == n - 1)
			cout << endl;
		else
			cout << " ";
	}
	cout << sum << endl;
}
