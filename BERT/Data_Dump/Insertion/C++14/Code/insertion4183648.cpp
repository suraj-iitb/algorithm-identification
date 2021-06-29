#include<bits/stdc++.h>
using namespace std;
int N;

int main() {
	int M;
	cin >> M;
	vector<int>a(M);
	for (int i = 0;i < M;i++) {
		cin >> a[i];
		if (i != 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
	for (int i = 1;i < M;i++) {
		int v;
		v = a[i];
		int j;
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (int k = 0;k < M;k++) {
			if (k != 0) cout << " ";
			cout << a[k];
		}cout << endl;
	}
	return 0;
}
