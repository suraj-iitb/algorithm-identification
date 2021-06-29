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

	int mi, tmp, cut = 0;
	rep(i, n - 1) {
		mi = i;
		for (int j = i; j < n; j++) {
			if (a[mi] > a[j])
				mi = j;
		}
		if (mi != i) {
			cut++;
			tmp = a[mi];
			a[mi] = a[i];
			a[i] = tmp;
		}
	}

	rep (i, n) {
		if (i > 0) cout << ' ';
		cout << a[i];
	}
	cout << endl;
	cout << cut << endl;

}

