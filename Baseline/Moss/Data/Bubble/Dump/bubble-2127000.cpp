#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int kaisu = 0;
	int l[100];
	int n, tmp;
	int d = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l[i];
	}
	if (n == 1) {
		cout << l[0] << endl << 0 << endl;
	}else {
		for (;;) {
			for (int i = n - 1; i > 0; i--) {
				if (l[i] < l[i - 1]) {
					tmp = l[i];
					l[i] = l[i - 1];
					l[i - 1] = tmp;
					kaisu += 1;
				}
			}
			d += 1;
			if (d == n - 1) {
				break;
			}
		}
		sort(l, l + n);
		for (int i = 0; i < n; i++) {
			cout << l[i];
			if (i == n - 1) {
				cout << endl;
			}
			else cout << " ";
		}
		cout << kaisu << endl;
	}
	char c;
	cin >> c;
}
