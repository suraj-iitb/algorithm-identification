#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	for (int i = 1; i < n; i++) {		
		for (int j = 0; j < n; j++) {
			cout << V[j];
			if (j < n - 1)
				cout << " ";
			else
				cout << endl;
		}
		int j = i - 1;
		while (j >= 0 && V[j] > V[j + 1]) {
			int a = V[j + 1];
			V[j + 1] = V[j];
			V[j] = a;
			j--;
		}
	}
	for (int j = 0; j < n; j++) {
		cout << V[j];
		if (j < n - 1)
			cout << " ";
		else
			cout << endl;
	}
}
