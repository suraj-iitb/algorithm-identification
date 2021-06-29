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
	int minj;
	for (int i = 0; i < n - 1; i++) {
		minj = i;
		for (int j = i ; j < n; j++) {
			if (V[j] < V[minj]) {
				minj = j;
			}				
		}
		if (i != minj) {
			swap(V[i], V[minj]);
			sum++;
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
