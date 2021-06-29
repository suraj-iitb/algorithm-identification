#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,v,j;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num.at(i);
		printf("%d", num.at(i));
		if (i != n - 1)cout << ' ';
		else cout << endl;
	}

	for (int i = 1; i < n; i++) {
		v = num.at(i);
		j = i - 1;
		while (j >= 0 && num.at(j) > v) {
			num.at(j + 1) = num.at(j);
			j--;
		}
		num.at(j + 1) = v;

		for (int k = 0; k < n; k++) {
			printf("%d", num.at(k));
			if (k != n - 1)cout << ' ';
			else cout << endl;
		}
	}
}
