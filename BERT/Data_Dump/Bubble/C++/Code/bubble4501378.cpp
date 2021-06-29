#include <bits/stdc++.h>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	rep(i, n) 
		cin >> a[i];

	int tmp;
	int cut = 0;
	rep (i, n - 1) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				cut++;
			}
		}
	}

	rep(i, n) {
		if (i > 0) cout << ' ';
		cout << a[i];
	}
	cout << endl;

	cout << cut << endl;

}

