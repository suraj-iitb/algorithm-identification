#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,j=0;
	int tmp=0;
	int v[1000];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int k = 0; k < n; k++) {
		if (k != 0) {
			cout << " ";
		}
		cout << v[k] ;
	}
	cout << endl;

	for (int i = 1; i < n; i++) {
		j = i-1;
		tmp = v[i];
		while (j >= 0 && v[j] > tmp) {
			v[j + 1] = v[j];
			j--;
		}
		v[j+1] = tmp;
		for (int k = 0; k < n; k++) {
			if (k != 0) {
				cout << " ";
			}
			cout << v[k];
		}
		cout << endl;
	}


	//cout << ans << endl;

	return 0;
}
